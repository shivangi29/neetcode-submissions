class Solution {
public:
    int m,n;
    bool checkE(vector<vector<char>>& board, string word, int i, int j, int k, vector<vector<bool>>& vis) {
        //cout<<"func"<<endl;
        //cout<<" i "<<i<<" j "<<j<<" k "<<k<<endl;
        if(k == word.size()) return true;
        if(i==m || j==n || i<0 || j<0) return false;
        if(vis[i][j] || word[k] != board[i][j]) return false;
        
        //cout<<"board"<<board[i][j]<<endl;
        vis[i][j] = true;
        if( checkE(board, word, i+1, j, k+1, vis)
                || checkE(board, word, i-1, j, k+1, vis)
                || checkE(board, word, i, j+1, k+1, vis)
                || checkE(board, word, i, j-1, k+1, vis) )
                return true;
        vis[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n; j++) {
                if(board[i][j] == word[0]) {
                    if(checkE(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};
