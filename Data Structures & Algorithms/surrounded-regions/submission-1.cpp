class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    //vector<vector<int>> vis;
    int m, n;
    void dfs(int i, int j, vector<vector<char>>& board) {
        board[i][j] = 'Z';
        for (auto& dir : directions) {
            int x=i+dir[0], y=j+dir[1];
            if(x>=0 && y>=0 && x<m && y<n && board[x][y] == 'O') {
                board[x][y] = 'Z';
                dfs(x,y,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(); n= board[0].size();
        //vis = vector<vector<int>>(m, vector<int>(n,0));
        for(int i = 0; i < m;i++) {
            if(board[i][0] == 'O')
                dfs(i,0,board);
            if(board[i][n-1] == 'O')
                dfs(i,n-1, board);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O')
                dfs(0,j,board);
            if(board[m-1][j] == 'O')
                dfs(m-1,j,board);
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
