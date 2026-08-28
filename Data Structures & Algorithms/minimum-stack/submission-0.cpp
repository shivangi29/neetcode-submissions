class MinStack {
public:
    stack<int> mainStk;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStk.push(val);
    }
    
    void pop() {
        mainStk.pop();
    }
    
    int top() {
        return mainStk.top();
    }
    
    int getMin() {
        int m = INT_MAX;
        stack<int> tmp = mainStk;
        while(!tmp.empty()) {
            m = min(m, tmp.top());
            tmp.pop();
        }
        return m;
    }
};
