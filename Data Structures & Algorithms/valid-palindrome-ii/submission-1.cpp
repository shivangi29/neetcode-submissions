class Solution {
public:
    bool isPalim(int i, int j, string s) {
       while(i<j){
            if(s[i] != s[j]) {
                return false;
            }
            i++; j--;
       }
       return true; 
    }
    bool validPalindrome(string s) {
        int i = 0,j = s.size() - 1;

        while(i<j){
            if(s[i] == s[j]) {
                i++; j--; continue;
            }
            return isPalim(i+1,j,s) || isPalim(i,j-1,s);
        }
        return true;
    }
};