#define INF 2147483647
class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m, n;
    /*vector<vector<bool>> vis;
    void dfs(int i, int j,vector<vector<int>>& grid) {
        if(i>=m || j >=n || i<0 || j<0 || grid[i][j]==-1)
            return;
        vis[i][j] = 1;
        for(auto dir : directions) {
            int nx = i+dir[0]; int ny = j+dir[1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0
               && grid[nx][ny] != -1 && vis[nx][ny] != 1) {
                if(grid[nx][ny] <= 1+grid[i][j]) continue;
                grid[nx][ny] = 1;
                grid[nx][ny] = min(grid[nx][ny], 1+grid[i][j]);
                dfs(nx,ny,grid);
            }
        }
        vis[i][j] = 2;
    }*/
    void islandsAndTreasure(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> que;
        //vis = vector<vector<bool>>(m, vector<bool>(n,false));
                    
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j <n ;j++) {
                if(grid[i][j] == 0) {
                    que.push({i,j});
                }
            }
        }
        while(!que.empty()) {
            int sz = que.size();
            while(sz--) {
                auto [i,j] = que.front();
                que.pop();
                for(auto dir : directions) {
                    int nx = i+dir[0]; int ny = j+dir[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]!=0
                        && grid[nx][ny] != -1) {
                        if(grid[nx][ny] <= 1+grid[i][j]) continue;
                        grid[nx][ny] = min(grid[nx][ny], 1+grid[i][j]);
                        que.push({nx,ny});
                   }
                }
            }
        }
    }
};
