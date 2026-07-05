class Solution {
public:
    #define isAlpha(ch) ((ch >= 'a' && ch <= 'z') ||  (ch >='0' && ch <= '9') || (ch >= 'A' && ch <= 'Z'))

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while(i<j) {
            //cout<<s[i]<<"1. "<<s[j]<<endl;
            
            if(!isAlpha(s[i])) {
                //cout<<"s[i]"<<s[i]<<endl;
                i++; continue;
            } 
            if(!isAlpha(s[j])) {
                //cout<<"s[j]"<<s[j]<<endl;
                j--; continue;
            }
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32; // Or: return ch | 0x20;
            }
            if (s[j] >= 'A' && s[j] <= 'Z') {
                s[j] = s[j] + 32; // Or: return ch | 0x20;
            }
            //cout<<s[i]<<"2. "<<s[j]<<endl;
            
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
