class Solution {
public:
    unordered_set<string> map;
    int find(string& s , int st, vector<int>& dp) {
        if(st == s.size()) {
            return 0;
        }
        if(dp[st] != -1)
            return dp[st];
        int res = 1 + find(s, st+1, dp);
        for(int i = st; i < s.size(); i++) {
            string sub = s.substr(st, i-st+1);
            if(map.count(sub)) {
                res = min(res, find(s, i+1, dp));
            }
        }
        return dp[st] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        map.insert(dictionary.begin(), dictionary.end());
        vector<int> dp(s.size(), -1);
        return find(s, 0, dp);
    }
};