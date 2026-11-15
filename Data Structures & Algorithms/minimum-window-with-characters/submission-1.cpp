class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size()) {
            return "";
        }

        unordered_map<char, int> map;
        for (char ch : t) {
            map[ch]++;
        }

        int st = 0, i = 0;
        int count = t.size();
        int minLen = INT_MAX;
        int minStart = 0;

        while (i < s.size()) {
            // Only decrement count if s[i] is still needed
            if (map.contains(s[i])) {
                if (map[s[i]] > 0) {
                    count--;
                }
                map[s[i]]--; // Surplus characters become negative
            }
            i++;

            // Shrink the window from the left while all characters are matched
            while (count == 0) {
                if (i - st < minLen) {
                    minLen = i - st;
                    minStart = st;
                }

                if (map.contains(s[st])) {
                    map[s[st]]++;
                    // If count goes above 0, we just lost a required character
                    if (map[s[st]] > 0) {
                        count++;
                    }
                }
                st++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
