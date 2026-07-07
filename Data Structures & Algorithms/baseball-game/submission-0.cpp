class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stk;
        int ans = 0;
        for(int i = 0 ; i < operations.size(); i++) {
            int n = stk.size();
            switch (operations[i][0]) {
                case '+':
                    stk.push_back(stk[n-1] + stk[n-2]);
                    ans += stk.back();
                    break;
                case 'D': 
                    stk.push_back(stk[n-1] * 2);
                    ans += stk.back();
                    break;
                case 'C':
                    ans -= stk.back();
                    stk.pop_back();
                    break;
                default:
                    stk.push_back(stoi(operations[i]));
                    ans += stk.back();
            }
        }
        return ans;
    }
};