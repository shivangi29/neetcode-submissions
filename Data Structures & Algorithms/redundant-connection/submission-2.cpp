class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;
    set<pair<int,int>> hash;
    int n = 1000;
    int st, end;
    void dfs(int i, int par){
        vis[i] = 1;
        for(int ad : adj[i]) {
            if(vis[ad] && ad == par)
                continue;
            if(vis[ad]) {
                hash.insert({min(ad,i), max(ad,i)});
                st = ad, end = i;
                return;
            }
            dfs(ad, i);
        }
        vis[i] = 2;
    }
    bool paths(int i, int par) {
        if(i == end) return true;
        vis[i] = 1;
        int ret = false;
        for(int ad : adj[i]) {
            if(vis[ad] && par == ad) continue;
            if(paths(ad, i)) {
                hash.insert({min(ad,i), max(ad,i)});
                ret = true;
            }
        }
        vis[i] = 2;
        return ret;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vis = vector<int>(n+1, 0);
        adj = vector<vector<int>>(n+1);
         for(auto ed : edges) {
            adj[ed[0]].push_back(ed[1]);
            adj[ed[1]].push_back(ed[0]);
        }
        dfs(1, 0);
        std::fill(vis.begin(), vis.end(), 0);
         cout<<" st "<<st<<" end "<<end<<endl;
               
        paths(st, 0);
        
        for(auto [a,b] : hash){
            cout<<"["<<a<<","<<b<<"] ";
        }
        for(int i = edges.size()-1; i>=0;i--) {
            if(hash.contains({min(edges[i][0],edges[i][1]), max(edges[i][0],edges[i][1])}))
                return edges[i];
        }
        return {};
    }
};
