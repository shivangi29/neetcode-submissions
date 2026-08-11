class Solution {
public:
    vector<int> par, sz;
    int count = 0;
    void join(int i, int j) {
        int pi = findPar(i);
        int pj = findPar(j);
        if(pi == pj) return;
        count--;
        if(sz[pi] > sz[pj]) {
            par[pj] = pi;
            sz[pi] += sz[pj];
        } else {
            par[pi] = pj;
            sz[pj] += sz[pi];
        }
    }
    int findPar(int i) {
        if(par[i] == i)
            return i;
        return par[i] = findPar(par[i]);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        sz.resize(n);
        count = n;
        for(int i = 0 ; i < n; i++) {
            par[i] = i;
            sz[i] = 1;   
        }
        // Loop over the edge vectors properly 
        for (const auto& edge : edges) {
            join(edge[0], edge[1]);        
        }
        
        
        return count;
    }
};
