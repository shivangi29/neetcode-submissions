class Solution {
public:
    int res = 0;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int res = 1;
        vector<int> dp(n, 1);
        for(int i = n-2;i>=0;i--) {
            for(int j = i+1; j<n;j++) {
                if(nums[j]>nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(dp[i], res);
                }
            }
        }
        for(int a : dp)
            cout<<a<<" ";
        return res;
    }
};
