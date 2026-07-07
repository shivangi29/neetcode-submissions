class Solution {
public:
    bool match(char top, char ch){
        if((top == '[' && ch == ']') 
            || (top == '(' && ch == ')') || (top == '{' && ch == '}')) 
            return true;
        return false;
    }
    bool isValid(string s) {
        vector<char> stk;
        for(int i = 0 ; i < s.size(); i++) {
            if(!stk.empty() && match(stk.back(), s[i]))
                stk.pop_back();
            else stk.push_back(s[i]);
        }
        return stk.empty();
    }
};
