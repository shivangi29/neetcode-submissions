class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1, i = digits.size()-1;
        do {
            int d = digits[i];
            digits[i] = (d+c)%10;
            c = (d+c)/10;
            i--;
        } while(c != 0 && i >=0);
        if (!c) return digits;
        vector<int> ans = {1};
        for(auto i : digits)
            ans.push_back(i);
        return ans;
    }
};
