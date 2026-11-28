class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max = nums[0], cur_min = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int tmp = cur_max;
            cur_max = max(nums[i], max(cur_min*nums[i], cur_max*nums[i]));
            cur_min = min(nums[i], min(cur_min*nums[i], tmp*nums[i]));
            ans = max(ans, max(cur_max, cur_min));
        }
        return ans;
    }
};
