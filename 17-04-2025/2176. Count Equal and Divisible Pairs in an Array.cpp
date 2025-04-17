class Solution {
public:
    int countPairs(const vector<int>& nums,const int k,int ans = 0) {
        const int n = nums.size();

        for(int i = 0;i < n-1;i++){
            for(int j = i+1;j < n;j++){
                if(nums[i] == nums[j] && (i*j)%k == 0) ans++;
            }
        }

        return ans;
    }
};
