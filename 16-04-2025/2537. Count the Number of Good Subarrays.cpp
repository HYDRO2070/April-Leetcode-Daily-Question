class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        long long ans = 0
        for (int i = 0, left = 0 ; i < nums.size() ; i++) {
            k -= m[nums[i]]++;
            while (k <= 0) k += --m[nums[left++]];
            ans += left;
        }
        return ans;
    }
};
