class Solution {
public:
    int n, count;
    int countSubstrings(string s) {
        n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        count = 0;
        
        for (int i = n-1; i>=0; i--) {
            for (int j = i; j < n; j++) {
                if(s[i] == s[j] && (j-i<=2 || dp[i+1][j-1])) {
                    count++;
                    dp[i][j] = 1;
                }
            }
        }
        
        return count;
    }
};
