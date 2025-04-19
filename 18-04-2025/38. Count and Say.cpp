class Solution {
public:
    string countAndSay(const int n) {
        string res = "1";

        for (int i = 2; i <= n; ++i) {
            string curr;
            const int len = res.size();
            curr.reserve(len * 2);

            for (int j = 0; j < len;) {
                int cnt = 1;
                while (j + cnt < len && res[j] == res[j + cnt]) {
                    ++cnt;
                }
                curr.append(to_string(cnt)).append(1, res[j]);
                j += cnt;
            }

            res = move(curr);
        }

        return res;
    }
};
