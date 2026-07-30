class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());    
        if (dead.contains("0000") || dead.contains(target)) return -1;
        if (target == "0000") return 0;
        
        unordered_set<string> set1 = {"0000"};
        unordered_set<string> set2 = {target};
        unordered_set<string> visited = {"0000", target};
        int steps = 0;
        
        while (!set1.empty() && !set2.empty()) {
            if (set1.size() > set2.size()) {
                swap(set1, set2);
            }
            
            unordered_set<string> next_set;
            steps++; 

            for (string curr : set1) {
                for (int i = 0; i < 4; i++) {
                    char orig = curr[i];
                    
                    for (int diff : {-1, 1}) {
                        char next_digit = (orig - '0' + diff + 10) % 10 + '0';
                        curr[i] = next_digit;
                        
                        if (set2.contains(curr)) {
                            return steps;
                        }
                        
                        if (!dead.contains(curr) && !visited.contains(curr)) {
                            visited.insert(curr);
                            next_set.insert(curr);
                        }
                    }
                    curr[i] = orig; // Restore original character
                }
            }
            // Move to the next level frontier
            set1 = move(next_set);
        }
        
        return -1;
    }
};
