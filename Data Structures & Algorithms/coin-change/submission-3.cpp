class Solution {
public:
    int n, count, gmax;
    vector<int> dp;
    int dfs(vector<int>& coins, int tar) {
        if(tar==0) {
            return 0;
        }
        if(tar<0) return INT_MAX;
        if(dp[tar] != -1)
            return dp[tar];
        int res = INT_MAX;
        for(int coin : coins) {
            if(coin <= tar) {
                int sub = dfs(coins, tar-coin);
                if(sub != INT_MAX)
                    res = min(res, 1 + sub);
            }
        }
        dp[tar] = res;
        return dp[tar];
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.resize(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1; i <=amount; i++) {
            for(int coin : coins) {
                if(coin<=i && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i-coin]);
                }
            }
        }
        return dp[amount]==INT_MAX ? -1:dp[amount];
    }
};
