class Solution {
public:
    long long maximumTripletValue(const vector<int>& nums) {
        long long ans = 0;
        int maxi = 0, diff = 0;
        for (auto& num : nums) {
            ans = max(ans, 1ll *diff * num);
            diff = max(diff, maxi - num);
            maxi = max(maxi, num);
        }
        return ans;
    }
};
