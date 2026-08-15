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
        dp.resize(n, -1);
        
        minCost(0, cost);
        //for(auto a : dp) cout<<a<<" ";
        //int res2 = minCost(1, cost);
        //for(auto a : dp) cout<<a<<" ";
        
        return min(dp[0], dp[1]);
    }
};
