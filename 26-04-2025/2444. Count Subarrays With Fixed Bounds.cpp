class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long res = 0;
        int lmin = -1, lmax = -1, linv = -1;
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                linv = i;
            }
            if (nums[i] == minK) {
                lmin = i;
            }
            if (nums[i] == maxK) {
                lmax = i;
            }
            res += max(0, min(lmin, lmax) - linv);
        }
        
        return res;
    }
};
