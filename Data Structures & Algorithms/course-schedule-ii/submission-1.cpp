class Solution {
public:
    vector<vector<int>> adj;
    vector<int> ans, vis;
    bool dfs(int st) {
        for(int ad : adj[st]) {
            if(vis[ad] == 2) continue;
            if(vis[ad] == 1) return true;

            vis[ad] = 1;
            if(dfs(ad))
                return true;;
        }
        vis[st] = 2;
        ans.push_back(st);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses,vector<int>());
        vis = vector<int>(numCourses, 0);
        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                vis[i] = 1;
                if(dfs(i))
                    return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
