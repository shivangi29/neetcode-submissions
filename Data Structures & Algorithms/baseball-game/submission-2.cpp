#include <vector>
#include <string>
#include <numeric>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::vector<int> stk;
        
        for (const std::string& op : operations) {
            // Check if the string is a command or a number
            if (op == "+") {
                int n = stk.size();
                int new_score = stk[n - 1] + stk[n - 2];
                stk.push_back(new_score);
            } 
            else if (op == "D") {
                stk.push_back(stk.back() * 2);
            } 
            else if (op == "C") {
                stk.pop_back();
            } 
            else {
                // Negative numbers and positive numbers safely end up here
                stk.push_back(std::stoi(op));
            }
        }
        
        // Sum up all elements left in the stack
        int ans = 0;
        for (int score : stk) {
            ans += score;
        }
        return ans;
    }
};
