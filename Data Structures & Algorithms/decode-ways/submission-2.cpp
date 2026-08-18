class Solution {
public:
    vector<int> memo;
    int find(int i, string s) {
        if(i>=s.size())
            return 1;

        if(s[i] == '0') 
            return 0;
        
        if(memo[i] != -1)
            return memo[i];

        int a = find(i+1, s);

        if(i+1 < s.size() ) {
            if(stoi(s.substr(i, 2)) <= 26)
                a += find(i+2, s);
        }
        return memo[i] = a;
    }
    int numDecodings(string s) {
        if(s.empty()) return 0;
        memo.assign(s.size(), -1);
        return find(0, s);
    }
};
