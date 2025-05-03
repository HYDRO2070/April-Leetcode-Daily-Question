class Solution {
public:
    long long countSubarrays(const vector<int>& nums, int k) {
        const int n = nums.size();
        long long res = 0;
        int j = 0;
        k *= -1;
        int maxi = *max_element(nums.begin(),nums.end());

        for(int i = 0;i < n;i++){
            if(nums[i] == maxi) k++;
            while(k >= 0){
                res += n - i;
                if(nums[j] == maxi) k--;
                j++;
            }
        }
        return res;
    }
};
