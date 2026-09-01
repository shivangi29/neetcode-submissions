class StockSpanner {
public:
    stack<pair<int,int>> stk;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        int small = 1;
        while(!stk.empty() && stk.top().first <= price) {
            small += stk.top().second;
            stk.pop();
        }
        stk.push({price,small});
        return small;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */