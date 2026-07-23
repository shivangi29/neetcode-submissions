class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0 ; i < 9; i++) {
            for(int j = 0 ; j < 9; j++) {
                char ch = board[i][j]; 
                if(ch != '.' ) {
                    for(int k = i+1; k<9; k++) {
                        if(board[k][j] == ch) {
                            //cout<<"1st";
                            return false;
                        }
                    }
                    for(int k = j+1; k<9; k++) {
                        if(board[i][k] == ch) {
                            //cout<<"2nd";
                            return false;
                        }
                    }
                    int imin, imax, jmin, jmax;
                    if(i < 3) { 
                        imax = 2; imin = 0;
                    } else if(i < 6) {
                        imax = 5; imin = 3;
                    } else {
                        imax = 8; imin = 6;
                    }
                    if(j < 3) {
                        jmax = 2; jmin = 0;
                    } else if(j < 6) {
                        jmax = 5; jmin = 3;
                    } else {
                        jmax = 8; jmin = 6;
                    }
                    for(int p = imin ;p <=imax;p++) {
                        for(int q = jmin ;q <=jmax;q++) {
                            if(p==i && q==j)
                                continue;
                            if(ch == board[p][q]) {
                                //cout<<"3rd";
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;   
    }
};
