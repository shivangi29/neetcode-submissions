class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first; // Max-heap: Largest distance stays on top
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int,int>>, Compare> pq;
        for(int i = 0 ; i < points.size(); i++) {
            int a = points[i][0];
            int b = points[i][1];
            pq.push({(a*a + b*b), i});
            if(pq.size() > k)
                pq.pop();
        }
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            ans.push_back({points[idx]});
        }  
        return ans;     
    }
};
