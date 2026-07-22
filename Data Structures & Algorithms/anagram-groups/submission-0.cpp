class Solution {
public:
    unordered_map<string, vector<string>> hash;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i = 0 ; i<strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            hash[s].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            ans.push_back(it->second); // it->second is the vector<string>
        }
        
        return ans;
    }
};
