class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis, in;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses,vector<int>());
        vis = vector<int>(numCourses, 0);
        in =  vector<int>(numCourses, 0);
        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
        }
        int tot = numCourses;
        while(1) {
            int avail = false;
            for(int i = 0; i < numCourses; i++) {
                if(!vis[i] && in[i] == 0) {
                    tot--;
                    avail = true;
                    vis[i] = 1;
                    for(int ad :adj[i]) {
                       in[ad]--; 
                    }
                }
            }
            if(tot == 0) break;
            if(avail == false) return false;
        }
        
        return true;
    }
};
