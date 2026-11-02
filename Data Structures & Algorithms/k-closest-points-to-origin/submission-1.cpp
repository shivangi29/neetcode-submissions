class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first; // Max-heap: Largest distance stays on top
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> pq;
        for(int i = 0 ; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];
            pq.push({(a*a + b*b), i});
        }
        for(int i = 0 ; i < k ; i++) {
            auto top = pq.top();
            pq.pop();
            int j = top.second;
            ans.push_back({points[j][0], points[j][1]});
        }  
        return ans;     
    }
};
