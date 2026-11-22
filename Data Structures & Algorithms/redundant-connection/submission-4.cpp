class DSU {
    public:
        DSU(int n) {
            par.resize(n+1);
            rank.resize(n+1,1);
            for(int i = 0;  i<=n; i++ ) {
                par[i] = i;
            }
        }
        int find(int i) {
            if(i == par[i]) return i;
            return par[i] = find(par[i]);
        }
        void Union(int i, int j) {
            int pari = find(i),  parj = find(j);
            if(pari == parj) {
                ans = {i,j};
                return;
            }
            if(rank[pari] < rank[parj]) {
                rank[parj] += rank[pari];
                par[pari] = parj;
            } else {
                rank[pari] += rank[parj];
                par[parj] = pari;
            }
        }
        vector<int> par, rank;
        vector<int> ans;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        DSU dsu(n);
        for(auto edge:edges) {
            dsu.Union(edge[0],edge[1]);
        }
            
        return dsu.ans;
    }
};
