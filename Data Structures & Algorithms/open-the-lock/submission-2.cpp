class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;
        
        // Edge case: if starting position is blocked
        if (dead.contains("0000")) return -1;
        // Edge case: if starting position is already the target
        if (target == "0000") return 0;
        
        queue<string> que;
        que.push("0000");
        vis.insert("0000");
        
        int steps = 0;
        
        while (!que.empty()) {
            int sz = que.size();
            
            // Process all nodes at the current distance level
            while (sz--) {
                string curr = que.front();
                que.pop();
                
                // Try all 8 possible next combinations
                for (int i = 0; i < 4; i++) {
                    char orig = curr[i];
                    
                    // Spin wheel forward
                    char fow = (orig - '0' + 1) % 10 + '0';
                    curr[i] = fow;
                    if (curr == target) return steps + 1;
                    if (!vis.contains(curr) && !dead.contains(curr)) {
                        vis.insert(curr);
                        que.push(curr);
                    }
                    
                    // Spin wheel backward
                    char bak = (orig - '0' - 1 + 10) % 10 + '0';
                    curr[i] = bak;
                    if (curr == target) return steps + 1;
                    if (!vis.contains(curr) && !dead.contains(curr)) {
                        vis.insert(curr);
                        que.push(curr);
                    }
                    
                    // Restore original character before moving to the next wheel index
                    curr[i] = orig;
                }
            }
            steps++; // Increment steps only after completing the entire level
        }
        
        return -1;
    }
};
