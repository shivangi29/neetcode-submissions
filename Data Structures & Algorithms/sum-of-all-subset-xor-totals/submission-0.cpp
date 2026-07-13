class Solution {
public:
    int sum;
    void findSum(int i, vector<int>& nums, int tmp) {
        if(i>=nums.size()) {
            sum += tmp;
            return;
        }
        findSum(i+1, nums, tmp);
        findSum(i+1, nums, tmp^nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        sum = 0;
        findSum(0,nums, 0);
        return sum;
    }
};