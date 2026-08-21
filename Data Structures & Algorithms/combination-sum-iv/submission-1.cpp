class Solution {
public:
    vector<int> memo;
    int find(vector<int>& nums, int target) {
        if(memo[target] != -1){
            return memo[target];
        }
        int res = 0;
        
        for(auto num : nums) {
            if(num <= target) {
                res += find(nums, target-num);
            }
        }
        return memo[target] = res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memo.assign(target+1, -1);
        memo[0] = 1;
        return find(nums, target);
    }
};