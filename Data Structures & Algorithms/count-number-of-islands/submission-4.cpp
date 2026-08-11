class Solution {
public:
    int m, n;
    vector<vector<int>> rank;
    vector<vector<pair<int,int>>> par;
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int islandCount = 0; // Optimization: Counter instead of a Set

    pair<int,int> findPar(int i, int j) {
        if(par[i][j].first == i && par[i][j].second == j)
            return {i,j};
        
        int next_i = par[i][j].first;
        int next_j = par[i][j].second;
        return par[i][j] = findPar(next_i, next_j);
    }

    void join(int i, int j, int u, int v) {
        pair<int,int> pij = findPar(i,j);
        int pi = pij.first, pj = pij.second;
        
        pair<int,int> puv = findPar(u,v);
        int pu = puv.first, pv = puv.second;
        
        if(pij == puv) return; // Already in the same island
        
        // Successful union: Two islands merge into one
        islandCount--; 
        
        if(rank[pi][pj] > rank[pu][pv]) {
            par[pu][pv] = pij;
        } else if(rank[pi][pj] < rank[pu][pv]) {
            par[pi][pj] = puv;
        } else {
            rank[pi][pj] += 1;
            par[pu][pv] = pij;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        if (m == 0) return 0;
        n = grid[0].size();
      
        par.resize(m, vector<pair<int,int>>(n, {-1,-1}));
        rank.resize(m, vector<int>(n, 0));
        islandCount = 0;
      
        // Step 1: Initialize parents and baseline island count
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == '1') {
                    par[i][j] = {i,j};
                    islandCount++; 
                }
            }
        }
        
        // Step 2: Traverse and union adjacent land masses
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == '1') {
                    for(auto& dir : directions) {
                        int nx = i + dir[0];
                        int ny = j + dir[1];
                        if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1'){
                            join(i, j, nx, ny);
                        } 
                    }
                }
            }
        }
        
        return islandCount;
    }
};
