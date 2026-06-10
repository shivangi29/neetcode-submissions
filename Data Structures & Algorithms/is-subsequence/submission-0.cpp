class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j = 0, i = 0, k = 0;
        for(i = 0 ; i< s.size(); i++) {
            for(j = k; j < t.size(); j++) {
                if(t[j] == s[i]) {
                    k = j+1;
                    break;
                }
            }
            if(j >= t.size()) {
                //cout<<j<<endl;
                return false;
            }
        }
        //cout<<i<<endl;
        return i == s.size();
    }
};