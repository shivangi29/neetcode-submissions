class Solution {
public:
    vector<string> ans;
    bool validate(string sub) {
        if(stoi(sub) > 255)
            return false;
        if(sub.size()>1 && sub[0] == '0')
            return false;
        return true;
    }
    void findIP(const string& s, string str, int i, int count) {
        if(count == 4) {
            if(i == s.size())
                ans.push_back(str);
            return;
        }
        int j = i;
        while(j < s.size() && j<i+3) {
            string sub = s.substr(i, j-i+1);
            if(validate(sub)) {
                if(!str.empty())
                    sub = str + "." + sub;
                findIP(s, sub, j+1, count+1);
            }
            j++;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        string str = "";
        findIP(s, str, 0, 0);
        return ans;
    }
};