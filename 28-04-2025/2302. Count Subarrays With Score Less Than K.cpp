class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long res = 0;
        vector<long long> pre(n,0);
        pre[0] = nums[0];
        for(int i = 1;i < n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i = 0;i < n;i++){
            int left = i;
            int right = n-1;
            int mid = left + (right - left) / 2;
            int ans = -1;
            while(left <= right){
                long long tsum = pre[mid];
                if(i-1 >= 0) tsum -= pre[i-1];
                tsum *= (mid-i+1);
                if(tsum < k){
                    left = mid+1;
                    ans = mid;
                }
                else right = mid - 1;
                mid = left + (right - left) / 2;
            }
            if(ans != -1)
            res += (ans - i)+1;
        }
        return res;
    }
};
