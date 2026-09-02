class Solution {
public:
    std::string decodeString(std::string s) {
        std::stack<int> counts;
        std::stack<std::string> strings;
        std::string current_str = "";
        int current_num = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0'); // Build multi-digit values
            } else if (c == '[') {
                counts.push(current_num);     // Save structural multiplier
                strings.push(current_str);   // Cache structural history
                current_num = 0;              // Reset counters
                current_str = "";
            } else if (c == ']') {
                std::string decoded_segment = strings.top();
                strings.pop();
                
                int repeat_times = counts.top();
                counts.pop();
                
                while (repeat_times--) {
                    decoded_segment += current_str;
                }
                current_str = decoded_segment; // Update buffer
            } else {
                current_str += c; // Build characters sequentially
            }
        }
        return current_str;
    }
};
