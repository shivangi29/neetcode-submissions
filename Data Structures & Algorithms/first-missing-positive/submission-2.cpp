class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            if(nums[i] <=0 || nums[i] > n){
                i++; continue;
            }
            int idx = nums[i] - 1;
            if(nums[i] != nums[idx]) {
                swap(nums[i], nums[idx]);
            } else {
                i++;
            }
        }
        for(i = 0 ; i < n ;i++) {
            if(nums[i] != (i+1))
                return i+1;
        }
        return n+1;
    }
};