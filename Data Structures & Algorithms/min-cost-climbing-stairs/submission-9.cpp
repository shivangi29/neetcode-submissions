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
        vector<int> dp(cost.size()+1, 0);
        return min(minCost(cost, 0, dp), minCost(cost,1, dp));
    }
};
