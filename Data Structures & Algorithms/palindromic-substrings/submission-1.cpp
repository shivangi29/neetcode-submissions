class Solution {
public:
    int n, count;
    void expand(int left, int right, string s) {
        while(left>=0 && right<n && s[left] == s[right]) {
            count++;
            left--; right++;
        }
    }
    int countSubstrings(string s) {
        n = s.size();
        count = 0;
        for(int i = 0; i < n;i++) {  
            count++;
            expand(i-1, i+1, s);
            expand(i, i+1, s);
        }
        return count;
    }
};
