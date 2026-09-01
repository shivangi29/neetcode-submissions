class Solution {
public:
    string simplifyPath(string path) {
        string ans = "";
        int n = path.size();
        int skip = 0;
        int i = n-1; 
        while(i>=0) {
            int end = i;
            while(end>=0 && path[end] == '/') {
                end--;
            }
            if(end<0) break;
            int st = end;
            while(st>=0 && path[st] != '/') {
                st--;
            }
            string str = path.substr(st+1,end-st);
            if(str == ".") {
            
            } else if(str == "..") {
                skip++;
            } else {
                if(skip==0)
                    ans = "/" + str + ans;
                else 
                    skip--;
            }
            i = st;
        }
        if(ans.size() == 0)
            return "/";
        return ans;
    }
};