class Solution {
public:
    vector<bool> vis;
    bool ana(string s1, string s2) {
        int n1 = s1.size(); 
        int n2 = s2.size();
        if(n1 != n2) return false;
        vector<int> a1(26,0);
        vector<int> a2(26,0);
        for(int i = 0 ; i < n1 ;i++) {
            a1[s1[i] - 'a']++;
            a2[s2[i] - 'a']++;
        }
        for(int i = 0 ; i < 26;i++) {
            if(a1[i] != a2[i])
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vis.resize(n, false);
        vector<vector<string>> ans;
        for(int i = 0 ; i<n ; i++) {
            if(!vis[i]) {
                vector<string> tmp;
                vis[i] = true;
                tmp.push_back(strs[i]);
                for(int j = i+1; j<n; j++) {
                    if(!vis[j]) {
                        if(ana(strs[i],strs[j])) {
                            vis[j] = true;
                            tmp.push_back(strs[j]);
                        }
                    }
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
