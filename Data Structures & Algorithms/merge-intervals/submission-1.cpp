class Solution {
public:
    static bool sortFunc(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sortFunc);
        int i = 1;
        int n = intervals.size();
        int pos = 0;
        while(i<n) {
            int st = intervals[i][0];
            int end = intervals[i][1];
            if(st<=intervals[pos][1]) {
                intervals[pos][0] = min(st,intervals[pos][0]),
                intervals[pos][1] = max(end,intervals[pos][1]);
            } else {
                pos++;
                intervals[pos] = intervals[i];
            }
            i++;
        }
        pos++;
        while(pos<n) {
            intervals.pop_back();
            pos++;
        }    
        return intervals;
    }
};
