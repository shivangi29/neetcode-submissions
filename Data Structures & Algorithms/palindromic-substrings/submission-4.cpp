class Solution {
public:
    int n, count;
    int countSubstrings(string s) {
        n = s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,0));
        count = 0;
        for(int i = 0 ; i < n ; i++) {
            count++;
            dp[i][i] = true;
        }
        for(int i = 0 ; i < n-1 ; i++) {
            if(s[i] == s[i+1]) {
                count++;
                dp[i][i+1] = true;
            }
        }
        for (int k = 3; k <= n; ++k) {
        for (int i = 0; i <= n - k; ++i) {
            int j = i + k - 1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                        count++;
                        dp[i][j] = 1;
                    }
                }
            }
        
        return count;
    }
};
