class Solution {
public:
    //set<pair<int,int>> edge_vis;
    vector<int> par, sz;
    int count;
    bool join(int i, int j) {
        int pi = findPar(i);
        int pj = findPar(j);
        if(pi == pj) return false;
        count--;
        if(sz[pi] > sz[pj]) {
            par[pj] = pi;
            sz[pi] += sz[pj];
        } else {
            par[pi] = pj;
            sz[pj] += sz[pi];
        }
        return true;
    }
    int findPar(int i) {
        if(par[i] == i) return i;
        return par[i] = findPar(par[i]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        par.resize(n);
        sz.resize(n,1);
        for(int i = 0 ; i < n; i++) {
            par[i] = i;
        }
        count = n;
        for(int i = 0 ; i < edges.size() ;i++) {
            if(join(edges[i][0], edges[i][1]) == false)
                return false; 
        }
        return count == 1;
    }
};
