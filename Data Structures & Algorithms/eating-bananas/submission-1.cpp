class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high) {
            int mid = (low+high)>>1;
            int k = 0;
            for(auto num : piles) {
                k += ((long long)num + mid - 1) / mid;;
            }
            if (k > h) {
                low = mid+1;
            } else {
                ans = min(ans, mid);
                high = mid -1;
            }
        }
        return ans;
    }
};
