class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0},
                                      {0, 1}, {0, -1}};
    vector<vector<int>> vis;
    int m, n;
    void fill(queue<pair<int,int>> que, vector<vector<int>>& heights, int oc) {
        while(!que.empty()) {
            auto [i,j] = que.front();
            que.pop();
            for (auto& dir : directions) {
                int x=i+dir[0], y=j+dir[1];
                //if(vis[i][j] == 2 && (i==m-1 || j==j-1)) continue;
                if(x>=0 && y>=0 && x<m && y<n && heights[x][y]>=heights[i][j]) {
                    if(vis[x][y] & oc) continue;
                    vis[x][y] |= oc;
                    que.push({x,y});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        m = heights.size(); n= heights[0].size();
        vis = vector<vector<int>>(m, vector<int>(n,0));
        queue<pair<int,int>> atl;
        queue<pair<int,int>> pac;
        
        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                if(i ==0 || j ==0) {
                    vis[i][j] |= 1;//1 for pac 
                    pac.push({i,j});
                }
                if(i == m-1 || j ==n-1){
                    vis[i][j] |= 2;
                    atl.push({i,j});
                }
            }
        }
        
        fill(pac, heights,1);
        fill(atl, heights,2);
        
        for(int i = 0; i < m;i++) {
            for(int j = 0 ;j<n; j++) {
                cout<<vis[i][j]<<" ";
                if(vis[i][j] == 3) {
                    ans.push_back({i,j});
                }
            }
            cout<<endl;
        }
        return ans;
    }
};
