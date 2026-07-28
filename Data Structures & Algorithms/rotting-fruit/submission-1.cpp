class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m, n;
    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> que;
        int fresh = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j <n ;j++) {
                if(grid[i][j] == 2) {
                    que.push({i,j});
                }
                if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        int time = 0;
        while(!que.empty()) {
            if(fresh == 0) return time;
            time++;
            int sz = que.size();
            while(sz--) {
                auto [i,j] = que.front();
                que.pop();
                for(auto dir : directions) {
                    int nx = i+dir[0]; int ny = j+dir[1];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1) {
                        fresh--;
                        grid[nx][ny] = 2;
                        que.push({nx,ny});
                   }
                }
            }
        }
        return fresh ? -1 : time - 1;
    }
};
