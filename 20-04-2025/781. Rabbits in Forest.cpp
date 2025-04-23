class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for (int i : answers) {
            mp[i]++;
        }
        int ans = 0;
        for (auto& item : mp) {
            ans +=
                ceil((double)item.second / (item.first + 1)) * (item.first + 1);
        }
        return ans;
    }
};
