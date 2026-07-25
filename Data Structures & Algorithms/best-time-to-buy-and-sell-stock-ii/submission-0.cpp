class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //int ma = prices[0];
        int mi = prices[0];
        int sum = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > mi) {
                sum += prices[i] - mi;
                mi = prices[i];
            } else {
                mi = prices[i];
            }
        }
        return sum;
    }
};