class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, i = 0;
        for(i = 0, j = 0 ; i< s.size(), j < t.size();) {
            if(t[j] == s[i]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};