class Solution {
public:
    int directions[4][2] = {{1,0},{0,1},{-1,0},{0, -1}};
    int peri, m, n;
    vector<vector<bool>> vis;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i>=m || j>=n || i<0 || j<0 || !grid[i][j]) {
            peri++;
            return;
        }
        if(vis[i][j])
            return;
        vis[i][j] = true;
        for(auto& dir : directions){
            dfs(i+dir[0],j+dir[1], grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), peri = 0;
        vis = vector<vector<bool>>(m, vector<bool>(n,false));
        for (int i = 0; i < m ;++i) {
            for (int j = 0; j < n; ++j) {
                if(grid[i][j]){
                    dfs(i,j,grid);    
                    return peri;
                }
            }
        }
        return 0;
    }
};