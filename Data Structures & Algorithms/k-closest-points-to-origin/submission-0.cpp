class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> dis, ans;
        for(int i = 0 ; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];
            dis.push_back({(a*a + b*b), i});
        }
        sort(dis.begin(),dis.end());
        for(int i = 0 ; i < k ; i++) {
            ans.push_back({points[dis[i][1]][0], points[dis[i][1]][1]});
        }  
        return ans;     
    }
};
