class Solution {
public:
    int m, n;
    vector<vector<char>> gri;
    void dfs(int i, int j) {
        if(i>=m || j>=n || i<0 || j<0 || gri[i][j]=='0')
            return;
        gri[i][j] = '0';
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j+1);
        dfs(i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        gri = grid;
        m = grid.size();
        n = grid[0].size();
        int count = 0;
        for(int i = 0 ; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                if(gri[i][j] == '1') {
                    count++;
                    dfs(i,j);
                }
            }
        }
        return count;
    }
};
