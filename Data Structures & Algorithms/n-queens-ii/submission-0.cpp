class Solution {
public:
    vector<vector<bool>> curr;
    vector<bool> col;
    int tot;
    bool check(int r, int c, int n) {
        for(int i = 0 ; i < r; i++) {
            for(int j = 0 ; j < n; j++) {
                if(i+j == r+c || i-j == r-c){
                    if(curr[i][j])
                        return false;
                }
            }
        }
        return true;
    }
    void solve(int i, int n) {
        if(i >= n) {
            tot++; return;
        }
        for(int j = 0; j < n; j++) {
            if(col[j]) continue;
            if(check(i,j,n)) {
                curr[i][j] = true;
                col[j] = true;
                solve(i+1, n);
                curr[i][j] = false;
                col[j] = false;
            }
        }
    }
    int totalNQueens(int n) {
        curr.assign(n, vector<bool>(n,false));
        col.assign(n, false);
        tot = 0;
        solve(0,n);    
        return tot;
    }
};