class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 0;
        int st = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        while(i<intervals.size()) {        
            if(intervals[i][0]<end) {
                count++;
            } else {
                end = intervals[i][1];
            }
            i++;
        }
        return count;
    }
};
