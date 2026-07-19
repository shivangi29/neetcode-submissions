class Solution {
public:
    vector<vector<string>> ans;
    int n;
    bool palin(string s, int i, int j) {
        while(i<=j) {
            if(s[i] != s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    void findSets(string s, int st, vector<string> tmp){
        if(st == n) {
            ans.push_back(tmp);
            return;
        }
        for(int i = st; i < n ; i++) {
            if(palin(s,st,i)) {
                tmp.push_back(s.substr(st, i - st + 1));
                findSets(s, i+1, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        findSets(s, 0, {});
        return ans;
    }
};
