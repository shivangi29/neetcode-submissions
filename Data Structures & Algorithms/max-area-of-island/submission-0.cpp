class Solution {
public:
    int gmax;
    int n,m;
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    void dfs(int i, int j, vector<vector<int>>& grid, int &lmax) {
        if(i<0 || j <0 || j>=n || i>=m || grid[i][j]==0)
            return;
        grid[i][j] = 0;
        lmax++;
        for(auto &dir : directions) {
            dfs(i+dir[0], j+dir[1], grid, lmax);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        gmax = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    int lmax = 0;
                    dfs(i,j,grid, lmax);
                    gmax = max(gmax,lmax);
                }
            }
        }
        return gmax;
    }
};
