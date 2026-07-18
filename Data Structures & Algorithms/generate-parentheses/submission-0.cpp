class Solution {
public:
    vector<string> ans;
    void find(int n, int m, string curr) {
        if(n == 0) {
            int t = m;
            while(t--){
                curr.push_back(')');
            }
            ans.push_back(curr);
            while(m--){
                curr.pop_back();
            }
            return;
        }
        curr.push_back('(');
        find(n-1, m, curr);
        curr.pop_back();

        if(m>n) {
            curr.push_back(')');
            find(n, m-1, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        find(n,n,"");
        return ans;
    }
};
