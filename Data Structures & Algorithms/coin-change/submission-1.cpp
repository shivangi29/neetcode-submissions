class Solution {
public:

    vector<int> memo;

    int dfs(vector<int>& coins, int amount) {

        if (amount == 0)
            return 0;

        if (memo[amount] != -1)
            return memo[amount];

        int res = INT_MAX;

        for (int coin : coins) {

            if (coin <= amount) {

                int sub = dfs(coins, amount - coin);

                if (sub != INT_MAX)
                    res = min(res, 1 + sub);
            }
        }

        return memo[amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {

        memo.resize(amount + 1, -1);

        int ans = dfs(coins, amount);

        return ans == INT_MAX ? -1 : ans;
    }
};