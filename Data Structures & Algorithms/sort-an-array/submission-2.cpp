class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //[12, 11, 13, 5, 6]
        
        for(int i = 1; i < n; i++) {
            int key = nums[i];
            int j = i-1;
            for(j = i-1; j>=0 && nums[j]>key; j--) {
                nums[j+1] = nums[j];
            }
            nums[j+1] = key;
        }
        return nums;
    }
};