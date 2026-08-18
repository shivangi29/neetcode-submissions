class Solution {
public:
    // Use a vector to remember results for each index
    vector<int> memo;

    int find(int i, string& s) {
        if (i >= s.size()) return 1;
        
        if (s[i] == '0') return 0;
        
        if (memo[i] != -1) return memo[i];

        // Option 1: Take a single digit
        int ways = find(i + 1, s);

        // Option 2: Take two digits if valid (between 10 and 26)
        if (i + 1 < s.size()) {
            int twoDigit = stoi(s.substr(i, 2));
            if (twoDigit <= 26) {
                ways += find(i + 2, s);
            }
        }

        // Save and return the result
        return memo[i] = ways;
    }

    int numDecodings(string s) {
        if (s.empty()) return 0;
        // Initialize memo array with -1
        memo.assign(s.size(), -1);
        return find(0, s);
    }
};
