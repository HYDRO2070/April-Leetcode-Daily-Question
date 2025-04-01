class Solution {
    // using recursion function
    // private:
    // long long solve(vector<vector<int>>& q,int index,vector<long long> &dp){
    //     if(index >= q.size()) return 0;
    //     if(dp[index] != -1) return dp[index];

    //     return dp[index] = max(q[index][0] + solve(q,index+q[index][1]+1,dp),solve(q,index+1,dp));

    // }
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1,0);

        // using lamda function
        // function<long long(int)> solve = [&](int index) -> long long{
        //     if(index >= q.size()) return 0;
        //     if(dp[index] != -1) return dp[index];

        //     return dp[index] = max(q[index][0] + solve(index+q[index][1]+1),solve(index+1));
        // };

        for(int index = n-1;index >= 0;index--){
            long long ans = q[index][0];
            if(index + q[index][1]+1 < n)
                ans += dp[index+q[index][1]+1];
            if(index+1 < n)
                ans = max(ans,dp[index+1]);
            dp[index] = ans;
        }

        // return solve(0);
        return dp[0];
    }
};
