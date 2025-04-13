#define MOD 1000000007

class Solution {
private:
    long long modPow(long long num, long long n) {
        long long res = 1;
        num %= MOD;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * num) % MOD;
            num = (num * num) % MOD;
            n /= 2;
        }
        return res;
    }

public:
    int countGoodNumbers(const long long n) {
        const long long even = (n + 1) / 2;
        const long long odd = n / 2;
        return (modPow(5, even) * modPow(4, odd)) % MOD;
    }
};
