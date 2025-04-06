class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1);    
        vector<int> prev(n, -1); 

        int mindex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[mindex]) {
                mindex = i;
            }
        }

        vector<int> ans;
        for (int i = mindex; i >= 0; i = prev[i]) {
            ans.push_back(nums[i]);
            if (prev[i] == -1) break;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
