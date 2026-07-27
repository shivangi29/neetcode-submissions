class Solution {
public:
    int m, n;
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(grid[i][j] == '1') {
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    count++;
                    while(!que.empty()) {
                        auto [x,y] = que.front();
                        grid[x][y] = '0';
                        que.pop();
                        for(auto& dir : directions){
                            int nx = x+dir[0];
                            int ny = y+dir[1];
                            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny] == '1'){
                                que.push({x+dir[0], y+dir[1]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
