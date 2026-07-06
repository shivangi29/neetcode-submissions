class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = 0;
        for(int i = 1 ; i < prices.size(); i++) {
            if(prices[i] > buy)
                sell = max(sell, prices[i] - buy);
            buy = min(buy, prices[i]);
        }
        return sell;
    }
};
