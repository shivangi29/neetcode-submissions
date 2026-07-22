class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++) {
            int pos = 0;

            for(int j = 1; j < n-i;j++) {
                if(nums[pos] < nums[j]) {
                    pos = j;
                }
            }
            swap(nums[n-i-1], nums[pos]);
        }
        return nums;
    }
};