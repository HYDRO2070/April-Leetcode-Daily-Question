class Solution {
    private:
    bool solve(vector<int> &arr,int sum,int index,vector<vector<int>> &dp){
        if(sum == 0) return true;
        if(sum < 0 || index >= arr.size()) return false;
        if(dp[sum][index] != -1) return dp[sum][index];
        
        bool ans = solve(arr,sum - arr[index],index + 1,dp);
        if(!ans)
            ans = solve(arr,sum,index+1,dp);
        return dp[sum][index] = ans;
    }
public:
    bool canPartition(vector<int>& arr) {
        int sum = 0;
        for(auto& n : arr) sum += n;
        if(sum &1) return false;
        sum /= 2;
        vector<vector<int>> dp(sum+1,vector<int>(arr.size(),-1));
        return solve(arr,sum,0,dp);
    }
};
