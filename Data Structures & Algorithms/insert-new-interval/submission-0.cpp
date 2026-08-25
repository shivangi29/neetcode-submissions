class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
     int a = newInterval[0], b = newInterval[1];
     vector<vector<int>> ans;
     bool inserted = false;
     for (const auto& interval : intervals) {
        int st = interval[0];
        int end = interval[1];
        if(inserted || a > end) {
            ans.push_back({st,end});
        } else {
            if(b < st) {
                inserted = true;
                ans.push_back({a,b});
                ans.push_back({st,end});
            } else {
                a = min(st, a);
                b = max(end,b);
                //ans.push_back({a,b});
            }
        }
     }
     if(inserted == false)
        ans.push_back({a,b});
    return ans;
//[1,3],[4,6],[9,10]]    [1,8]
    }
};
