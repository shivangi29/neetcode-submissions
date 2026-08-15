class Solution {
public:
    int money(int i, vector<int>& nums, int n, vector<int>& dp) {
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int a = nums[i] + money(i+2, nums, n, dp);
        int b = money(i+1, nums, n, dp);
        //cout<<a<<" "<<b<<endl;
        dp[i] = max(a,b);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        if(n == 3) return max(nums[0], max(nums[1], nums[2]));

        vector<int> dp1(n,-1);
        vector<int> dp0(n,-1);

        money(1, nums, n, dp1);
        money(0, nums, n-1, dp0);
        
        return max(dp0[0],dp1[1]);
    }
};
