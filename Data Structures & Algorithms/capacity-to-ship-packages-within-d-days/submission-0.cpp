class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(), weights.end(), 0);
        int low = *max_element(weights.begin(), weights.end());
        int ans = high;
        while(low<=high) {
            int mid = (low + high)>>1;
            int tot = 1, sum = 0;
            for(int i = 0 ; i < weights.size(); i++) {
                if(sum+weights[i] > mid) {
                    tot++;
                    sum = 0;
                }
                sum += weights[i];
            }
            if(tot > days) {
                low = mid+1;
            } else {
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};