class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        dict = {'b':0,'a':0, 'l':0,'o':0,'n':0}
        for ch in text:
            if ch in dict:
                dict[ch] += 1
        dict['l'] = dict['l']//2
        dict['o'] = dict['o']//2
        return min(dict.values())