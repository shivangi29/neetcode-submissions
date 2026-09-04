class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(256, -1);
        int ans = 0, st = 0, i;
        for(i = 0 ; i < s.size(); i++) {
            int idx = s[i];
            if(arr[idx] != -1) {
                ans = max(ans, i-st);
                for(int j = st; j < arr[idx]; j++){
                    arr[s[j]] = -1;
                }
                st = arr[idx]+1;
            } 
            arr[idx] = i;
        }
        return max(i-st,ans);
    }
};
