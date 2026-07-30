class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    queue<int> q;
    void bfs() {
        while(!q.empty()) {
            int i = q.front();
            q.pop();
            for(int ad : adj[i]) {
                if(!vis[ad]) {
                    vis[ad] = 1;
                    q.push(ad);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n);
        vis = vector<bool>(n, false);
        for(int i = 0 ; i <edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);        
        }
        
        int comp = 0;
        for(int i = 0 ; i < n; i++) {
            if(!vis[i]) {
                comp++;
                q.push(i);
                vis[i] = 1;
                bfs();
            }
        }
        return comp;
    }
};
