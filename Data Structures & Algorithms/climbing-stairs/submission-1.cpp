class Solution {
public:
    vector<int> dp;
    int findSteps(int i) {
        if(i<0) return 0;
        if(dp[i]) return dp[i];
        
        dp[i] = findSteps(i-1) + findSteps(i-2);
        return dp[i];
    }
    int climbStairs(int n) {
        dp.resize(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        return findSteps(n);
    }
};
