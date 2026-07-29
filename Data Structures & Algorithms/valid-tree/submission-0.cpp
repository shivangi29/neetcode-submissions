class Solution {
public:
    set<pair<int,int>> edge_vis;
    vector<int> vis;
    vector<vector<int>> adj;
    bool dfs(int i) {
        vis[i] = 1;
        for(int ad : adj[i]) {
            if(vis[ad] && (!edge_vis.contains({i,ad}) && !edge_vis.contains({ad,i})) )
                return true;
            if(vis[ad]) continue;
            edge_vis.insert({i, ad});
            if(dfs(ad))
                return true;;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vis = vector<int>(n,false);
        adj = vector<vector<int>>(n);
        int count = 0;
        for(int i = 0 ; i < edges.size() ;i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            count++;
        }
        if(count != n-1) return false;
        if(dfs(0))
            return false;
        for(int i = 0 ; i < n; i++) {
            if(!vis[i])
                return false;
        }
        //connected no-cycle n-1 edges
        return true;
    }
};
