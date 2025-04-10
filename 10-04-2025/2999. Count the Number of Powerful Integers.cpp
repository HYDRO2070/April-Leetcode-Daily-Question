// Brute Force
class Solution {
    unordered_map<string, long long> memo;
    int size;

    long long solve(string &s, long long start, long long finish, int limit) {
        if (s.size() > size) return 0;
        long long num = stoll(s);
        if (num > finish) return 0;
        // if (memo.count(s)) return memo[s];


        long long ans = (num >= start && s[0] != '0') ? 1 : 0;

        for (int i = 0; i <= limit; ++i) {
            char ch = '0' + i;
            s = ch + s;
            long long temp = ans;
            ans += solve(s, start, finish, limit);
            s.erase(s.begin());
            if (i != 0 && temp == ans) break; 
        }

        // return memo[s] = ans;
        return ans;
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string &s) {
        memo.clear();
        if (stoll(s) > finish) return 0;
        size = to_string(finish).size();
        return solve(s, start, finish, limit);
    }
};



// Optimize Version

class Solution {
    private:
    string suffix;
    int limit;
    long long dp[20][2];

    long long countValid(const string &numStr) {
        int n = numStr.size();
        memset(dp, -1, sizeof(dp));

        function<long long(int, bool)> dfs = [&](int pos, bool tight) -> long long {
            if (pos == n) return 1;

            if (dp[pos][tight] != -1) return dp[pos][tight];

            long long res = 0;
            int maxDigit = tight ? numStr[pos] - '0' : 9;
            int suffixStart = n - suffix.size();

            if (pos >= suffixStart) {
                int idx = pos - suffixStart;
                int digit = suffix[idx] - '0';

                if (digit <= maxDigit && digit <= limit) {
                    res += dfs(pos + 1, tight && (digit == maxDigit));
                }
            } else {
                for (int d = 0; d <= maxDigit && d <= limit; ++d) {
                    res += dfs(pos + 1, tight && (d == maxDigit));
                }
            }

            return dp[pos][tight] = res;
        };

        return dfs(0, true);
    }

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, const string &s) {
        this->limit = limit;
        this->suffix = s;

        long long suffixNum = stolong long(s);
        if (finish < suffixNum) return 0;

        long long countToFinish = countValid(to_string(finish));
        long long countToStart = (start > suffixNum) ? countValid(to_string(start - 1)) : 0;

        return countToFinish - countToStart;
    }
};
