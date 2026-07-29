class Solution {
public:
    vector<vector<int>> adj;
    vector<int>vis;
    bool findCycle(int st) {
        vis[st] = 1;
        for(int ad : adj[st]) {
            if(vis[ad]==2) continue;
            if(vis[ad]==1) return true;
            vis[ad] = 1;
            if(findCycle(ad))
                return true;
        }
        vis[st] = 2;
        return false; 
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses,vector<int>());
        vis = vector<int>(numCourses, 0);
        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i++) {
            if(!vis[i]) {
                if(findCycle(i)==true) {
                    return false;
                }
            }
        }
        return true;
    }
};
