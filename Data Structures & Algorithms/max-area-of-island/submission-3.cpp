class Solution {
public:
    vector<int> rank, par;
    int gmax;
    int n,m;
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    int index(int i, int j){
        return i*n + j;
    }
    void DSU(int tot, vector<vector<int>>& grid) {
        par.resize(tot);
        rank.resize(tot);
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j]==1) {
                    int idx = index(i,j);
                    par[idx] = idx;
                    rank[idx] = 1; 
                    gmax = max(gmax, 1);
                }
            }
        }
    }
    void join(int i, int j) {
        int pi = findPar(i);
        int pj = findPar(j);
        if(pi == pj) return;
        if(rank[pi] < rank[pj]) {
            par[pi] = par[pj];
            rank[pj] += rank[pi];
            gmax = max(rank[pj], gmax);
        } else {
            par[pj] = par[pi];
            rank[pi] += rank[pj];
            gmax = max(rank[pi], gmax);
        }
    }

    int findPar(int i) {
        if(par[i] == i) return i;
        return par[i] = findPar(par[i]);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        gmax = 0;
        
        DSU(m*n, grid);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    for(auto &dir : directions) {
                        int x = i+dir[0], y = j+dir[1];
                        if(x>=0 && y>=0 && x<m && y<n && grid[x][y]) {
                            int u = index(i,j);
                            int v = index(x,y);
                            join(u,v);
                        }
                    }
                }
            }
        }
        return gmax;
    }
};
