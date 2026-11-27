class Solution {
public:
    int minCost(vector<int>& cost, int i, vector<int>& dp) {
        if(i >= cost.size())
            return 0;
        if(dp[i])
            return dp[i];
        int a = cost[i] + minCost(cost, i+1, dp);
        int b = cost[i] + minCost(cost, i+2, dp);
        dp[i] = min(a,b);
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n<=2) {
            if(n == 1) return cost[0];
            return min(cost[0], cost[1]);
        }
        vector<int> dp(cost.size(), 0);
        dp[n-1] = cost[n-1];
        dp[n-2] = cost[n-2];
        for(int i = n-3; i>=0; i--) {
            dp[i] = cost[i] + min(dp[i+1], dp[i+2]);
        }
        return min(dp[0], dp[1]);
    }
};
