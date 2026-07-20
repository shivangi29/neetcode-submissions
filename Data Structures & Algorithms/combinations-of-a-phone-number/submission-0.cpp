class Solution {
public:
    vector<vector<char>> key {{},{},
                              {'a','b','c'}, {'d','e','f'},
                              {'g','h','i'}, {'j','k','l'},
                              {'m','n','o'}, {'p','q','r','s'},
                              {'t','u','v'}, {'w','x','y','z'} };
        
    vector<string> ans;
    void findCombo(int i, string tmp, string digits) {
        if(i == digits.size()) {
            ans.push_back(tmp);
            return;
        }
        int dig = digits[i] - '0';
        cout<<dig<<endl;
        for(int j = 0 ; j < key[dig].size();j++) {
            tmp.push_back(key[dig][j]);
            findCombo(i+1, tmp, digits);
            tmp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return ans;
        findCombo(0,"", digits);
        return ans;
    }
};
