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
        if(n<=2) return 1;
        int res = 1;
        dp = vector<int>(n+1, -1);
        
        return tryBreak(n);
    }
};