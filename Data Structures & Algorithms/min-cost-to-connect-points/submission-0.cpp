class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        using vec = vector<int>;
        int n = points.size();
        priority_queue<vec, vector<vec>, greater<vec>> pq;
        pq.push({0,0});

        vector<int> vis(n,0);
        int ans = 0;
        while(!pq.empty() && n) {
            auto arr = pq.top();
            pq.pop();
            int i = arr[1];
            if(vis[i]) continue;
            int cost = arr[0];
            ans += cost;
            int x = points[i][0], y = points[i][1];
            n--;
            vis[i] = 1;
            for(int j = 0; j < points.size(); j++) {
                if(vis[j] || j==i) continue;
                int dis = abs(points[j][0]-x)+abs(points[j][1]-y);
                pq.push({dis, j});
            }
            
        }
        return ans;
    }
};
