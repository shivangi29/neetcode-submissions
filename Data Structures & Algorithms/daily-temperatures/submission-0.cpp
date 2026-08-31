class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> stk;
        for(int i = 0 ; i < temperatures.size() ; i++) {
            int a = temperatures[i];
            while(!stk.empty() && a > stk.top().first) {
                int idx = stk.top().second;
                ans[idx] = i - idx;
                stk.pop();
            }
            stk.push({a,i});    
        }
        return ans;
    }
};
