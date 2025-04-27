class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans = 0;
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if(b == (a+c)*2) ans++;
        for(int i = 3;i < nums.size();i++){
            a = b;
            b = c;
            c = nums[i];
            if(b == (a+c)*2) ans++;
        }
        return ans;
        
    }
};
