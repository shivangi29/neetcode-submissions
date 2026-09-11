class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int high = accumulate(nums.begin(), nums.end(), 0);
        int low = *max_element(nums.begin(), nums.end());
        int res = INT_MAX;
        while(low <= high) {
            int mid = (low+high)>>1;
            int tot = 1, sum = 0, max_sum = INT_MIN;
            for(auto num : nums){
                if(sum+num > mid) {
                    tot++;
                    max_sum = max(sum, max_sum);
                    sum = 0;
                }
                sum += num;
            }
            max_sum = max(sum, max_sum);
            if(tot < k) {
                high = mid-1;
            } else if(tot == k){
                res = min(max_sum, res);
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return res==INT_MAX ? low:res ;
    }
};