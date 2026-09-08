class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0, i = 0, sum = 0, res = 0;
        while(l < nums.size()) {
            if(r < nums.size() && sum < target) {
               sum += nums[r];
               r++;
            } else if (sum >= target){
                res = (res==0 ? (r-l) : min(res, r-l));
                sum -= nums[l];
                l++;
            } else {
                break;
            }
        }
        return res;
    }
};