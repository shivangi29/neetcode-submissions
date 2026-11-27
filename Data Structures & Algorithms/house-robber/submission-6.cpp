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
        vector<int> dp(nums.size(), 0);
        return startRob(nums, 0, dp);
    }
};
