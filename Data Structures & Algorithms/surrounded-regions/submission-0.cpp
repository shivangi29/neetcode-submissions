class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    //vector<vector<int>> vis;
    int m, n;
        
    void solve(vector<vector<char>>& board) {
        m = board.size(); n= board[0].size();
        //vis = vector<vector<int>>(m, vector<int>(n,0));
        queue<pair<int,int>> que;
        for(int i = 0; i < m;i++) {
            if(board[i][0] == 'O')
                que.push({i,0});
            if(board[i][n-1] == 'O')
                que.push({i,n-1});
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                que.push({0,j});
            if(board[m-1][j] == 'O')
                que.push({m-1,j});
        }    
        while(!que.empty()) {
            auto [i,j] = que.front();
            que.pop();
            board[i][j] = 'Z';
            for (auto& dir : directions) {
                int x=i+dir[0], y=j+dir[1];
                if(x>=0 && y>=0 && x<m && y<n && board[x][y] == 'O') {
                    board[x][y] = 'Z';
                    que.push({x,y});
                }
            }
        }
        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                if(board[i][j] == 'Z')
                    board[i][j] = 'O';
            }
        }
    }
};
