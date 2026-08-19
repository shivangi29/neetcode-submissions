class Solution {
public:
    unordered_set<string> hash;
    vector<int> memo;
    int check(string s, int st) {
        if(st >= s.size()) return 1;
        if(memo[st] != -1)
            return memo[st];
        int res = 0;
        for(int i = st; i<s.size();i++) {
            string sub = s.substr(st, i-st+1);
            if(hash.count(sub) != 0) {
                res = check(s,i+1);
                if(res) break;
            }
        }
        return memo[st] = res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        hash = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo.assign(s.size(), -1);
        return check(s, 0);
    }
};
