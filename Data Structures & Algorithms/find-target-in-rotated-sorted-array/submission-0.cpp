class Solution {
public:
    int bs(int low, int high, int target, vector<int>& nums) {
        while(low <= high) {
            int mid = (low+high)>>1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int h = high;
        while(low < high) {
            int mid = (low+high) >> 1;
            if(nums[mid] > nums[high]) {
                low = mid+1;
            } else {
                high = mid;
            }
        }
        int ans;
        if(target >= nums[high] && target <= nums[h]){
            ans = bs(high, h, target, nums);
        } else {
            ans = bs(0, high-1, target, nums);
        }
        return ans;
    }
};
