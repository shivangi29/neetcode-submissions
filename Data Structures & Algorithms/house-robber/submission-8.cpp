class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        int b = nums[n-1];
        int a = max(nums[n-1], nums[n-2]);
        int c = 0;
        for(int i = n-3; i>=0; i--) {
            c = max(nums[i]+b, a);
            b = a; a = c;
        }
        return c;
    }
};
