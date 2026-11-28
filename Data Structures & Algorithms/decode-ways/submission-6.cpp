class Solution {
public:
    int decode(string s, int i, vector<int>& dp) {
        if(i >= s.size()) {
            return 1;
        }
        if(s[i] == '0')
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int dig1 = s[i] - '0';
        int res = decode(s, i+1, dp);

        if(i+1 < s.size()) {
            int dig2 = dig1*10 + (s[i+1] - '0');
            if(dig2 <= 26) {
                res += decode(s, i+2, dp);
            }
        }
        dp[i] = res;
        return dp[i];
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return decode(s, 0, dp);
    }
};
