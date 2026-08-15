class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        dp.resize(n, -1);
        int a = nums[n-1];
        int b = max(nums[n-1], nums[n-2]);
        for(int i = n-3; i>=0; i--) {
            int c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return b;
    }
};
