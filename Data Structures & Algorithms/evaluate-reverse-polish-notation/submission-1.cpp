class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string str : tokens) {
            if(str=="+" || str=="-" || str=="*" || str=="/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                if(str=="+")
                    s.push(a+b);
                else if(str=="-")
                    s.push(a-b);
                else if(str=="*")
                    s.push(a*b);
                else
                    s.push(a/b);
            } else {
                s.push(stoi(str));
            }
        } 
        return s.top();  
    }
};
