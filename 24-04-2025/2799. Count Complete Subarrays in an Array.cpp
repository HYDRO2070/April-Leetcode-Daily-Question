class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> s;
        int res = 0;
        for(int& num : nums) s.insert(num);
        int n = s.size();

        for(int i = 0;i <= nums.size()-n;i++){
            s.clear();
            for(int j = i;j < nums.size();j++){
                s.insert(nums[j]);
            if(s.size() == n) res++;
            }
        }

        return res;
    }
};
