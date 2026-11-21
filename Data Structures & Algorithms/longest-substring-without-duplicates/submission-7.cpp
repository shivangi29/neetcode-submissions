class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> map(256, -1);
        int ans=0, i=0, j=0;
        while(j < s.size()) {
            while(j < s.size() && map[s[j]] == -1){
                map[s[j]] = j;
                j++;
            }
            ans = max(ans, j-i);
            if(j >= s.size())
                break;
            int st = i, end = map[s[j]];
            for(int k = st ; k <= end; k++)
                map[s[k]] = -1;
            map[s[j]] = j;
            i = end+1;
            j++;
        }
        return max(ans, j-i);
    }
};
