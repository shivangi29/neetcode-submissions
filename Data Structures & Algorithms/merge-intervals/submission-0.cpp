class Solution {
public:
    static bool sortFunc(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), sortFunc);
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
