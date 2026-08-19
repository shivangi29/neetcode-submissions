class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMax = 1;
        int curMin = 1;
        for (int num : nums) {
            int tmp = curMax * num;
            curMax = max(num, max(curMax*num, curMin*num));
            curMin = min(num, min(tmp, curMin*num));
            res = max(res,curMax);
        }
        return res;
    }
};
