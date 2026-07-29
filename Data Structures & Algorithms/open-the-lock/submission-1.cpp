class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int steps = 0;
        set<string> dead(deadends.begin(), deadends.end());
        set<string> vis;
        queue<string> que;
        que.push("0000");
        vis.insert("0000");
        if(dead.contains("0000")) return -1;
        while(!que.empty()) {
            int sz = que.size();
            steps++;
            while(sz--) {
                string tmp = que.front();
                if(tmp==target) return steps;
                que.pop();
                

                for(int i = 0 ; i < 4 ; i++) {
                    string top = tmp;
                    int dig = top[i]-'0';
                    int fow = (dig + 1)%10;
                    int bak = (dig - 1 < 0) ? 9 : dig-1;
                    top[i] = '0' + fow;
                    if(!vis.contains(top) && !dead.contains(top)) {
                        vis.insert(top);
                        que.push(top);
                    }
                    
                    if(top==target) return steps;
                    top[i] = '0' + bak;
                    if(!vis.contains(top) && !dead.contains(top)) {
                        vis.insert(top);
                        que.push(top);  
                    }

                    if(top==target) return steps;
                }
            }
        }
        return -1;
    }
};