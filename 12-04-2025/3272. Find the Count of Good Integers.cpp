class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        long long result = 0;

        int m = (n + 1) / 2;

        int start = pow(10, m - 1);
        int end = pow(10, m) - 1;

        unordered_set<string> st;

        for (int i = start; i <= end; i++) {
            string left = to_string(i);
            string full = "";
            if (n % 2 == 0) {
                string right = left;
                reverse(right.begin(), right.end());
                full = left + right;
            } else {
                string right = left.substr(0, m - 1);
                reverse(right.begin(), right.end());
                full = left + right;
            }

            long long number = stoll(full);
            if (number % k != 0) {
                continue;
            }

            sort(full.begin(), full.end());
            st.insert(full);
        }

        

        vector<long long> factorial(11, 1);
        for (int i = 1; i < 11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }


        for (const string& it : st) {
            vector<int> count(10, 0);
            for (const char& it1 : it) {
                count[it1 - '0']++;
            }

            int total = it.size();
            int zero = count[0];
            int non_zero = total - zero;

            long long perm = (non_zero * factorial[total - 1]);

            for (int i = 0; i < 10; i++) {
                perm /= factorial[count[i]];
            }

            result += perm;
        }

        return result;
    }
};
