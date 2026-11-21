class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();
        int count = 0;
        int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int, int>> q;
        for(int i = 0 ; i < m ;i++)  {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j]=='1') {
                    q.push({i,j});
                    count++;
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        auto [a,b] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int x = a+dir[k][0], y = b+dir[k][1];
                            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]=='1') {
                                grid[x][y] = '0';
                                q.push({x,y});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
