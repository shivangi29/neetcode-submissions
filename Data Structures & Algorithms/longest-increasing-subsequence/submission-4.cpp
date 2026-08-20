class Solution {
public:
    int gmax = 0;
    vector<int> dp;
    int findLIS(vector<int>& nums, int st){
        if(dp[st] != -1)
            return dp[st];
        dp[st] = 1;
        
        for(int i = st+1; i<nums.size(); i++) {
            if(nums[i] > nums[st]) {
                dp[st] = max(dp[st], 1 + findLIS(nums, i));
            }
        }
        return dp[st];
    }
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size(), -1);
        for(int i = 0 ; i< nums.size();i++) {
            gmax = max(gmax,findLIS(nums,i));
        }
        return gmax;
    }
};
