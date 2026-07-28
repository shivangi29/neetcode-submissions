class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    vector<vector<int>> vis, ans;
    int m, n;
        
    void dfs(int i, int j, vector<vector<int>>& heights, int oc) {
        vis[i][j] |= oc;
        
        for (auto& dir : directions) {
            int x=i+dir[0], y=j+dir[1];
            
            //if(vis[i][j] == 2 && (i==m-1 || j==j-1)) continue;
            if(x>=0 && y>=0 && x<m && y<n) {
                if(vis[x][y] & oc) continue;
                if( ((x==0 || y==0) && oc==1) || ((x==m-1 || y==n-1) && oc==2) ||
                    heights[x][y]>=heights[i][j])
                    dfs(x,y,heights,oc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(); n= heights[0].size();
        vis = vector<vector<int>>(m, vector<int>(n,0));

        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                if(i==0 || j==0)
                    dfs(i, j, heights, 1);
                if(i==m-1 || j==n-1)
                    dfs(i, j, heights, 2);
            }
        }
        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                //cout<<vis[i][j]<<" ";
                if(vis[i][j] == 3) {
                    ans.push_back({i,j});
                }
            }
            //cout<<endl;
        }
        return ans;
    }
};
