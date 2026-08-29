class MinStack {
public:
    stack<int> s;
    stack<int> ms;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        ms.push(ms.empty() ? val : min(val, ms.top()));
    }
    
    void pop() {
        s.pop();
        ms.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
