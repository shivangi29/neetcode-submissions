class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        dict1 = {}
        dict2 = {}
        words = s.split()
        if len(pattern) != len(words):
            return False
        for ch, word in zip(pattern, words):
            if ch in dict1:
                if dict1[ch] != word:
                    return False
            if word in dict2:
                if dict2[word] != ch:
                    return False
            dict1[ch] = word
            dict2[word] = ch
        return True
