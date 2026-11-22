class Solution {
public:
    bool dfs(int src, vector<int>& vis, vector<vector<int>>& adj) {
        vis[src] = 1;
        for(auto neigh : adj[src]) {
            if(vis[neigh] == 1) {
                cout<<" src "<<src<<" neigh "<<neigh<<endl;
                return false;
            }
            if(!vis[neigh])
                 if(!dfs(neigh, vis, adj))
                    return false;
        }
        vis[src] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses,0);

        for(auto& edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            in[edge[0]]++;
        }
        vector<int> vis(numCourses, 0);
        queue<int> queue;
        for(int i = 0 ; i < numCourses ;i++) {
            if(in[i] == 0) {
                queue.push(i);
            }
        }
        while(!queue.empty()) {
            int sz = queue.size();
            numCourses -= sz;
            while(sz--) {
                int src = queue.front();
                queue.pop();
                for(auto& dst : adj[src]) {
                    in[dst]--;
                    if(in[dst] == 0)
                        queue.push(dst);
                }
            }
        }
        return numCourses ? false:true;
    }
};
