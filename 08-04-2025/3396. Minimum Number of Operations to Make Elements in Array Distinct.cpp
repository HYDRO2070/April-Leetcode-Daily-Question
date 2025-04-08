class Solution {
public:
    int minimumOperations(const vector<int>& nums,int index = 0) {
        int n = nums.size();
        if(index >= n) return 0;
        unordered_set<int> s;
        bool flag = false;
        for(int i = index;i < n;i++){
            if(s.find(nums[i]) != s.end()){
                flag = true;
                break;
            }
            s.insert(nums[i]);
        }
        if(flag) return 1 + minimumOperations(nums,index+3);
        return 0;
    }
};
