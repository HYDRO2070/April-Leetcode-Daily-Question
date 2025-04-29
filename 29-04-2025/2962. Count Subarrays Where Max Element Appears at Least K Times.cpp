class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k){
    long long count=0,i=0,j=0,sum=0;
    long long maxi=*max_element(nums.begin(),nums.end());
    for(long long i=0;i<nums.size();i++){
        if(maxi==nums[i])count++;
            while(count>=k){
                sum=sum+(nums.size()-i);
                if(maxi==nums[j])count--;
                j++;
            }
        }
    return sum;
}
};
