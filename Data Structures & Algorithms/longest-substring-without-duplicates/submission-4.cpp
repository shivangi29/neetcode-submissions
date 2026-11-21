class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int ans = 0, i=0,j = 0;
        while(j < s.size()) {
            while(j < s.size() && !map.contains(s[j])){
                map[s[j]] = j;
                j++;
            }
            ans = max(ans, j-i);
            if(j >= s.size())
                break;
            int st = i, end = map[s[j]];
            for(int k = st ; k <= end; k++)
                map.erase(s[k]);
            map[s[j]] = j;
            i = end+1;
            j++;
        }
        return max(ans, j-i);
    }
};
