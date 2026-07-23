class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string str : strs) {
            string len = to_string(str.size());
            ans += len + '#' + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        int n = s.size();
        while(i < n) {
            int st = i;
            string len = "";
            while(s[i] != '#') {
                i++; 
            } 
            //cout<<len<<endl;
            int sz = stoi(s.substr(st, i - st));
            string str = s.substr(i+1, sz);
            //cout<<str<<endl;
            ans.push_back(str);
            i += sz + 1;
        }
        return ans;
    }
};
