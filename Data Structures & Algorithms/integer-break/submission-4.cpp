class Solution {
public:
    vector<int> dp;
    int tryBreak(int sum) {
        if(dp[sum] != -1) 
            return dp[sum];
        int prod = 0;
        for(int i = 1; i<sum; i++) {
            prod = max(prod ,max(i*(sum-i) , i*tryBreak(sum-i)));
        }
        return dp[sum]=prod;
    }
    int integerBreak(int n) {
        int res = 1;
        dp = vector<int>(n+1, 0);
        for(int i = 1; i<=n; i++) {
            for(int j = 1; j < i;j++) {
                dp[i] = max(dp[i] ,max(j*(i-j) , j*dp[i-j]));
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};