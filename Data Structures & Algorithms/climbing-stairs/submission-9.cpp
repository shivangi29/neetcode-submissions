class Solution {
public:
    int climb(int n, vector<int>& dp) {
        if(n<=2)
            return dp[n];
        if(dp[n] != 0)
            return dp[n];
        dp[n] = climb(n-1,dp) + climb(n-2,dp);
        return dp[n];
    
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        if(n<=2)
            return n;
        dp[1] = 1; dp[2] = 2;
        return climb(n, dp);
    }
};
