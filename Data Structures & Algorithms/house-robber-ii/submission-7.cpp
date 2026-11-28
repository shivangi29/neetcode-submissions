class Solution {
public:
    int startRob(vector<int>& nums, int i, bool flag, vector<int>& dp) {
        if(!flag && i >= nums.size())
            return 0;
        if(flag && i >= nums.size()-1)
            return 0;
        if(dp[i] != 0)
            return dp[i];
        dp[i] =  max(startRob(nums, i+1, flag, dp), 
                nums[i] + startRob(nums,i+2, flag, dp) );
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0], nums[1]);
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        int a = startRob(nums, 1, false, dp1);
        int b = startRob(nums, 0, true, dp2);
        return max(a,b);
    }
};
