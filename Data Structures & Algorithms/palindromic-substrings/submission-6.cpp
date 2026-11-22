class Solution {
public:
    int n, count;
    int palin(int l, int r, string s) {
        int count=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            count++;
            l--;r++;
        }
        return count;
    }
    int countSubstrings(string s) {
        n = s.size();
        count = 0;
        
        for (int i = 0; i<n; i++) {
            count += palin(i,i,s) + palin(i,i+1,s); 
        }
        
        return count;
    }
};
