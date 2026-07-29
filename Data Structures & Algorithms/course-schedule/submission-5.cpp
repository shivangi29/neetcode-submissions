class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis, in;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj = vector<vector<int>>(numCourses,vector<int>());
        in =  vector<int>(numCourses, 0);
        queue<int> que;
        int tot = 0;
        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            in[prerequisites[i][0]]++;
            tot++;
        }
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int top = que.front();
            que.pop();
            
            for(int ad: adj[top]) {
                in[ad]--;
                tot--;
                if(in[ad] == 0)
                    que.push(ad);
            }
            if(tot == 0) break;
        }
        
        return tot==0;
    }
};
