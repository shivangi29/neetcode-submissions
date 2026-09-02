class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ma = 0;
        stack<int> stk;
        int i = 0;
        while(i<n) {
            if(stk.empty() || heights[i]>=heights[stk.top()]) {
                stk.push(i);
                i++;
            } else {
                int top = stk.top();
                stk.pop();
                int l = stk.empty() ? -1 : stk.top();
                int r = i;
                ma = max(ma, (r-l-1)*heights[top]);
            } 
        }
        while(!stk.empty()) {
            int top = stk.top();
            stk.pop();
            int l = stk.empty() ? -1 : stk.top();
            ma = max(ma, (n-l-1)*heights[top]);
        }
        return ma;
    }
};
