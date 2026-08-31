class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = n-1; i>=0  ; i--) {
            int a = temperatures[i];
            int j = i+1;
            while(j<n && ans[j] && temperatures[j]<=a) {
                j = j+ans[j];
            }
            if(j<n && temperatures[j]>a)
                ans[i] = j-i;    
        }
        return ans;
    }
};
