class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target+1, 0);
        memo[0] = 1;
        for(int sum = 1 ; sum<=target; sum++) {
            for(auto num : nums) {
                if(num <= sum) {
                    memo[sum] += memo[sum-num];
                }
            }
        }
        return memo[target];
    }
};