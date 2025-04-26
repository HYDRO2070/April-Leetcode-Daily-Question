class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long ans = 0, pre_sum = 0;
        unordered_map<long long, int> freq;

        freq[0]++;
        for (int j = 0; j < n; j++) {
            if (nums[j] % modulo == k) {
                pre_sum++;
            }
            ans += freq[(pre_sum - k + modulo) % modulo];
            freq[pre_sum % modulo]++;
        }
        return ans;
    }
};
