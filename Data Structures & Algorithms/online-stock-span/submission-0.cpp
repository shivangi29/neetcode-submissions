class StockSpanner {
public:
    vector<int> stocks;
    vector<int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int small = 1;
        
        int i = ans.size()-1;
        while(i>=0 && stocks[i] <= price) {
            small += ans[i];
            i -= ans[i];
        }
        stocks.push_back(price);
        ans.push_back(small);
        return small;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */