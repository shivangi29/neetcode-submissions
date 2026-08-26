class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 1;
        int st = intervals[0][0];
        int end = intervals[0][1];
        int i = 1;
        while(i<intervals.size()) {        
            int nxt_st = intervals[i][0];
            int nxt_end = intervals[i][1];
            if(nxt_st>=end) {
                count++; 
                end = nxt_end;
                st = nxt_st;
            } else if(nxt_end <= end) {
                end = nxt_end;
                st = nxt_st;
            }
            i++;
        }
        return intervals.size() - count;
    }
};
