class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n,false));
        int peri = 0;
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    que.push({i,j});
                    vis[i][j] = true;
                    while(!que.empty()) {
                        auto &[i,j] = que.front();
                        que.pop();

                        if(i+1==m) peri += 1;
                        if(j+1==n) peri += 1;
                        if(j-1<0) peri += 1;
                        if(i-1<0) peri += 1;

                        if(i+1 < m && !vis[i+1][j]) {
                            if(grid[i+1][j] == 1) {
                                vis[i+1][j] = true;
                                que.push({i+1,j});
                            } else   
                                peri += 1;
                        }
                        if(j+1 < n && !vis[i][j+1]) {
                            if(grid[i][j+1] == 1) {
                                que.push({i,j+1});
                                vis[i][j+1] = true;
                            }else 
                                peri += 1;
                        }
                        if(i-1 >= 0 && !vis[i-1][j]) {
                            if(grid[i-1][j] == 1) {
                                que.push({i-1,j});
                                vis[i-1][j] = true;
                            } else 
                                peri += 1;
                        }
                        if(j-1 >= 0 && !vis[i][j-1]) {
                            if(grid[i][j-1] == 1) {
                                que.push({i,j-1});
                                vis[i][j-1] = true;
                            } else 
                                peri += 1;
                        }
                    }
                    return peri;
                }
            }
        }
    }
};