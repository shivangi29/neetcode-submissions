class Solution {
public:
    vector<vector<string>> ans;
    vector<string> curr;
    vector<bool> col;
    bool check(int r, int c, int n) {
        for(int i = 0 ; i < r ; i++) {
            for(int j = 0 ; j < n ;j++) {
                if(r+c == i+j || r-c == i-j){
                    if(curr[i][j] == 'Q')
                        return false;
                }
            }
        }
        return true;
    }

    void solve(int r, int n) {
        if(r >= n) {
            ans.push_back(curr);
            return;
        }
        for(int j = 0; j<n ; j++) {
            if(col[j]) continue;

            if(check(r,j,n)) {
                col[j] = true;
                curr[r][j] = 'Q';
                solve(r+1,n);
                col[j] = false;
                curr[r][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string tmp = "";
        for(int i = 0 ; i < n ; i++) {
            tmp += ".";
        }
        curr.assign(n, tmp);
        col.assign(n,false);
        solve(0, n);

        return ans;
    }
};
