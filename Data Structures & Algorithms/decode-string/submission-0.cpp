class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        string ans = "";
        int n = s.size(), i = 0;
        while(i<n) {
            string num = "";
            string lett = "";
            while(i < n && s[i] >= '0' && s[i] <= '9') {
                num += s[i];
                i++;
            }
            if(num.size()) stk.push(num);
            if(i<n && (s[i] == '[') ) {
                stk.push(string(1, s[i]));
                i++;
            }
            while(i<n && s[i] >= 'a' && s[i] <= 'z') {
                lett += s[i];
                i++;
            }
            if(lett.size()) stk.push(lett);
            if(s[i]==']') {
                string top = "";
                while(!stk.empty() && stk.top() != "[") {
                    top = stk.top() + top;
                    stk.pop();
                }
                stk.pop();
                int rep = stoi(stk.top());
                stk.pop();
                string s = "";
                while(rep--) {
                    s+=top;
                }
                stk.push(s);
                i++;
            }
        }
        while(!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};