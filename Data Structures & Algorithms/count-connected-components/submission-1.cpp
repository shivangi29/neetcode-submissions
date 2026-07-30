class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(int i) {
        vis[i] = 1;
        for(int ad : adj[i]) {
            //if(ad == par) continue;
            if(!vis[ad])
                dfs(ad);
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
                dfs(i);
            }
        }
        return comp;
    }
};
