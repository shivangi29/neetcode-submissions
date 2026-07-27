class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0, -1}};
    int peri, m, n;
    vector<vector<bool>> vis;

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(i>=m || j>=n || i<0 || j<0 || !grid[i][j])
            return 1;
        if(vis[i][j])
            return 0;
        vis[i][j] = true;
        return dfs(i, j + 1, grid) + dfs(i + 1, j, grid) +
               dfs(i, j - 1, grid) + dfs(i - 1, j, grid);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), peri = 0;
        vis = vector<vector<bool>>(m, vector<bool>(n,false));
        for (int i = 0; i < m ;++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j]){
                    return dfs(i,j,grid);    
                }
            }
        }
        return 0;
    }
};