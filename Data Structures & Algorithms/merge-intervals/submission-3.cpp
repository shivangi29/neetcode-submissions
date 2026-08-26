class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 1;
        int n = intervals.size();
        ans.push_back(intervals[0]);
        while(i<n) {
            int st = intervals[i][0];
            int end = intervals[i][1];
            if(st>ans.back()[1]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[0] = min(st,ans.back()[0]),
                ans.back()[1] = max(end,ans.back()[1]);
            }
            i++;
        }
        return ans;
    }
};
