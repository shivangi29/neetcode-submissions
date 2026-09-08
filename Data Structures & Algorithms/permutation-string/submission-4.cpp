class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i = 0 ; i < s1.size(); i++) {
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i = 0; i < 26; i++) {
            if(arr1[i] == arr2[i])
                matches++;
        }

        int m = s1.size();
        int n = s2.size();
        for(int i = m; i < n; i++) {
            if(matches == 26)
                return true;
            
            if(arr1[s2[i]-'a'] == arr2[s2[i]-'a'])
                matches--;
            if(arr1[s2[i-m]-'a'] == arr2[s2[i-m]-'a'])
                matches--;
            arr2[s2[i]-'a']++;
            arr2[s2[i-m]-'a']--;
            
            
            if(arr1[s2[i]-'a'] == arr2[s2[i]-'a'])
                matches++;
            if(arr1[s2[i-m]-'a'] == arr2[s2[i-m]-'a'])
                matches++;
        }
        return matches == 26;
    }
};
