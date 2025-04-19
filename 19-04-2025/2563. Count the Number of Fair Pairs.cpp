class Solution {
public:
    long long countFairPairs(vector<int>& nums, const int lower, const int upper) {
        sort(nums.begin(), nums.end());
        long long res = 0;
        const int n = nums.size();

        for (int i = 0; i < n; ++i) {
            const int low = lower - nums[i];
            const int high = upper - nums[i];
            
            auto it_low = lower_bound(nums.begin() + i + 1, nums.end(), low);
            auto it_high = upper_bound(nums.begin() + i + 1, nums.end(), high);
            
            res += it_high - it_low;
        }

        return res;
    }
};
