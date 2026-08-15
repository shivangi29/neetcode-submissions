class Solution {
public:
    vector<int> dp;
    int n;
    int minCost(int i, vector<int>& cost) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int result = cost[i]+min(minCost(i+1, cost),minCost(i+2,cost));
        dp[i]=result;
        return result;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.resize(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i <n; i++) {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
};
