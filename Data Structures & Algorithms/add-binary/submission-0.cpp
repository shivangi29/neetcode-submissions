class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int m = a.size()-1, n = b.size()-1;
        int sum, c=0;
        while(m>=0 || n>=0) {
            int a1 = 0, b1 = 0;
            if(m>=0)
                a1 = a[m--]-'0';
            if(n>=0) 
                b1 = b[n--]-'0';
            sum = a1^b1^c;
            if(a1==1 && b1==1 && c==1)
                c = 1;
            else if(a1==1 && b1==1 || a1==1 && c==1 || b1==1 && c==1)
                c = 1;
            else c = 0;
            ans = to_string(sum) + ans;
        }
        if(c)
            ans = '1' + ans;
        return ans;
    }
};