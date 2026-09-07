class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26, 0);
        int left = 0, max_count = 0, max_len = 0;
        for(int right = 0; right < s.size(); right++) {
            arr[s[right]-'A'] += 1;
            max_count = max(arr[s[right]-'A'], max_count);
            int rem = right-left+1 - max_count;
            if(rem > k){
                max_len = max(max_len, right-left);
                arr[s[left]-'A'] -= 1;
                left++;
            }
        }
        max_len = max(max_len, (int)s.size()-left);
        return max_len;
    }
};
