class Solution {
public:
    long long maximumTripletValue(const vector<int>& nums) {
        // const int n = nums.size();

        // Brute Force
        // long long ans = INT_MIN;
        // for(int i = 0;i < n;i++){
        //     for(int j = i+1;j < n;j++){
        //         for(int k = j+1;k < n;k++){
        //             long long val = 1ll * (nums[i] - nums[j]) * nums[k];
        //             if(ans < val) ans = val;
        //         }
        //     }
        // }
        // return (ans < 0) ? 0 : ans;

        // optimized
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
