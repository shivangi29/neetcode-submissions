class Solution {
public:
    
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        unordered_map<int,unordered_set<int>> preq;

        for(int i = 0 ; i < prerequisites.size(); i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i = 0 ; i < numCourses; i++) {
            if(in[i] == 0)
                q.push(i);
        }
        while(!q.empty()) {
            for(int i = q.size(); i>0; i--) {
                int j = q.front();
                q.pop();
                for(int ad: adj[j]) {
                    preq[ad].insert(j);
                    preq[ad].insert(preq[j].begin(), preq[j].end());
                    in[ad]--;
                    if(in[ad] == 0) {
                        q.push(ad);
                    }
                }
            }
        }
        
        vector<bool> ans;
        for(auto ad : queries) {
            //ad[0] is a preq of ad[1] ==> preq(1)->0
            //uj is in list
            int src = ad[1], dst = ad[0];
            if(preq[src].contains(dst))
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};