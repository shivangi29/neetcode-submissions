class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        vector<int> in(numCourses, 0);
        vector<int> ans;
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
                ans.push_back(i);
            }
        }
        while(!que.empty()) {
            int top = que.front();
            que.pop();
            
            for(int ad: adj[top]) {
                in[ad]--;
                tot--;
                if(in[ad] == 0) {
                    ans.push_back(ad);
                    que.push(ad);
                }
            }
            if(tot == 0) return ans;
        }
        return {};
    }
};
