class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        s_count  = [0]*26
        
        for i in range(len(s)):
            s_count[ord(s[i]) - ord('a')] += 1
            s_count[ord(t[i]) - ord('a')] -= 1

        return all(x == 0 for x in s_count)