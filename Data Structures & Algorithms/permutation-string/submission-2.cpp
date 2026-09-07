class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*vector<int> arr1(26,0), arr2(26,0);
        for(auto a : s1)
            arr1[a-'a']++;
        */
        if(s1.size() > s2.size())
            return false;
        sort(s1.begin(), s1.end());
        int k = s1.size();
        for(int i=0; i<=s2.size()-k; i++) {
            string sub = s2.substr(i, k);
            sort(sub.begin(), sub.end());
            if(sub == s1)
                return true;
        }
        return false;
    }
};
