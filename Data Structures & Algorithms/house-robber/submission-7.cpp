class Solution {
public:
    int startRob(vector<int>& nums, int i, vector<int>& dp) {
        if(i >= nums.size())
            return 0;
        if(dp[i] != 0)
            return dp[i];
        dp[i] = max(startRob(nums,i+1, dp), nums[i]+startRob(nums,i+2,dp));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1], nums[n-2]);
        for(int i = n-3; i>=0; i--) {
            dp[i] = max(nums[i]+dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};
