class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        int ans = 0;
        vector<int> vis(n+1,0);
        using pii = std::pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0,k});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            ans = max(ans, dis);
            n--;
            if(n == 0) break;
            for(auto [dst,time] : adj[node]) {
                if(!vis[dst]) {
                    pq.push({dis+time, dst});
                }
            }
        }
        return n ? -1 : ans;
    }
};
