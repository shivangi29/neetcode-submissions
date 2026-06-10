class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        i = len(s)-1
        while(s[i] == ' ' and i >= 0):
            i = i-1
        
        j = i

        while(s[i] != ' ' and i >= 0):
            i = i-1
        
        return j-i
        