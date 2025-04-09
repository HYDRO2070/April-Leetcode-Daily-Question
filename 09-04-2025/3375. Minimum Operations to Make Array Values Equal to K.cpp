class Solution {
    
public:
    int minOperations(const vector<int>& nums, int k) {
        unordered_set<int> s;
        for(auto& num : nums){
            if(num > k) s.insert(num);
            if(num < k) return -1;
        }
        if(s.size()) return s.size();
        return 0;
    }
};
