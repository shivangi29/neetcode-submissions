class Solution {
public:
    
    int findNum(int sum, vector<int>& nums, vector<int>& dp) {
        if(dp[sum] != -1) return dp[sum];
     
        int res = INT_MAX;
        for(int num : nums) {
            if(num > sum)
                break;
            if(num <= sum) {
                res = min(res, 1 + findNum(sum-num, nums, dp));
            }
        }
        return dp[sum] = res;
    }
    int numSquares(int n) {
        vector<int> nums;
        for(int i = 1;  i*i<=n ; i++) {
            nums.push_back(i*i);
        }
        vector<int> dp(n+1, -1);
        dp[0] = 0;

        for(int sum = 1; sum<=n; sum++){
            dp[sum] = INT_MAX;
            for(int num : nums) {
                if(num > sum)
                    break;
                if(num <= sum) {
                    dp[sum] = min(dp[sum], 1 + dp[sum-num]);
                }
            }
        }
        return dp[n];
    }
};