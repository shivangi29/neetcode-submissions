class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int h = nums.size()-1, l = 0;
        while(l <= h) {
            int m = (l+h) >> 1;
            if(nums[m] == target)
                return true;
            
            if(nums[l] == nums[h] && nums[m] == nums[h]) {
                l++; h--;
            } else if(nums[l] == nums[m])
                l = m+1;
            else if(nums[m] == nums[h])
                h = m-1; 
            else if(nums[l] < nums[m]) {
                if(target >= nums[l] && target <= nums[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if(target >= nums[m] && target <= nums[h]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }
        return false;
    }
};