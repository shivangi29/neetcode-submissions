class Solution {
public:
    vector<string> ans;
    set<string> hash;
    void breakWord(string s, int st, vector<string> tmp){
        if(st >= s.size()) {
            string full = "";
            int i = 0;
            for(i = 0 ; i < tmp.size()-1; i++) {
                full += tmp[i];
                full += " ";
            }
            if(i >= 0) {
                full += tmp[i];
            } 
            ans.push_back(full);
            return;
        }
        for(int i = st; i < s.size(); i++) {
            string str = s.substr(st, i-st+1);
            if(hash.find(str) != hash.end()) {
                tmp.push_back(str);
                breakWord(s, i+1, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string str : wordDict)
            hash.insert(str);
        breakWord(s, 0, {});
        
        return ans;
    }
};