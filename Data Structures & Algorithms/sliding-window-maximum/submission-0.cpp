class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < k ; i++) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        for(int i = k ; i <nums.size(); i++) {
            pq.push({nums[i],i});
            int idx = pq.top().second;
            while(idx <= i-k) {
                pq.pop();
                idx = pq.top().second;
            }
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};
