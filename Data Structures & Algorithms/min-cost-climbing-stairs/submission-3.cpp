class Solution {
public:
    vector<int> dp;
    int n;
    int minCost(int i, vector<int>& cost) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = cost[i]+min(minCost(i+1, cost),minCost(i+2,cost));
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n+1, -1);
        return min(minCost(0, cost),minCost(1, cost));
    }
};
