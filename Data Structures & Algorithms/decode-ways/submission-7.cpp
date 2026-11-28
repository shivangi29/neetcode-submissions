class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 1;
        dp[n-1] = (s[n-1]-'0' > 0) ? 1:0;

        for(int i = n-2; i>=0; i--) {
            int dig1 = s[i] - '0';
            if(dig1 == 0) continue;
            dp[i] = dp[i+1];

            int dig2 = dig1*10 + (s[i+1]-'0');
            if(dig2 <= 26)
                dp[i] +=  dp[i+2];

        }
        return dp[0];
    }
};
