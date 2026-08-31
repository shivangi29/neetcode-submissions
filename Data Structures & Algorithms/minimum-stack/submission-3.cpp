class MinStack {
public:
    // Change this from int to long to support differences up to 4,294,967,295
    stack<long> s; 
    long min;
    
    MinStack() {}
    
    void push(int val) {
        if(s.empty()) {
            min = val;
            s.push(0);
        } else {
            s.push((long)val - min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long tmp = s.top();
        s.pop();
        if(tmp < 0) {
            min = min - tmp; // Restores previous min
        }
    }
    
    int top() {
        long tmp = s.top();
        if(tmp < 0) return min;
        return tmp + min;
    }
    
    int getMin() {
        return min;
    }
};
