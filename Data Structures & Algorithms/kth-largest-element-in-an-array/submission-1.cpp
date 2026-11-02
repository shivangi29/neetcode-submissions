class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> pq(nums.begin(), nums.end());
        int ans;
        k = nums.size() - k + 1;
        while(k--) {
            ans = pq.top(); pq.pop();
        }
        return ans;
    }
};
