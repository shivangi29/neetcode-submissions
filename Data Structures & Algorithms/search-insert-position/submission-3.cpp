class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int res = 0;
        while(l<=r) {
            int m = l + (r-l)/2;
            if(nums[m]==target)
                return m;

            if(nums[m] > target){
                res = m;
                r = m-1;
            } else 
                l = m+1;
        }
        return l;
    }
};