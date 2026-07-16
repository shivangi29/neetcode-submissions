class Solution {
public:
    vector<vector<int>> ans;
    void combo(int n, int k, vector<int> tmp) {
        if(k == 0){
            ans.push_back(tmp);
            return;
        }
        if(n <= 0) return;
        
        combo(n-1, k, tmp);
        tmp.push_back(n);
        combo(n-1,k-1,tmp);
        tmp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        combo(n, k, {});
        return ans;        
    }
};