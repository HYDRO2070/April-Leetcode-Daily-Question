class Solution {
public:
    vector<vector<int>> com;
#define mod 1000000007
    int comb(int n, int r) {
        if (n < r || n < 0 || r < 0)
            return 0;
        if (n == 0)
            return 0;
        if (r == 0)
            return 1;
        if (r == 1)
            return n;
        if (n == r)
            return 1;
        if (n - r < r)
            r = n - r;
        if (com[n][r] != -1)
            return com[n][r];
        com[n][r] = comb(n - 1, r - 1) + comb(n - 1, r);
        com[n][r] %= mod;
        return com[n][r];
    }

    int f(int n, int mx, int ele, int sze) {
        int i = 2;
        int ans = 0;
        while (ele * i <= mx) {
            ans = (ans + f(n, mx, ele * i, sze + 1) % mod) % mod;
            i++;
        }
        if (ele * i > mx) {
            ans = (ans + comb(n, sze - 1) % mod) % mod;
        }
        return ans;
    }
    int idealArrays(int n, int mx) {
        com.resize(10005, vector<int>(20, -1));
        return f(n, mx, 1, 1) % mod;
    }
};
