class Solution {
public:
    vector<int> dp;
    int money(int i , vector<int>& nums) {
        if(i>=nums.size())
            return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] =  max(nums[i]+money(i+2, nums), 
                    money(i+1, nums));
        return dp[i];
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), -1);
        money(0,nums);
        return dp[0];
    }
};
