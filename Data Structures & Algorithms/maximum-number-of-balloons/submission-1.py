from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        # 1. Count all letters in the text instantly
        counts = Counter(text)
        
        # 2. Return the limiting factor based on required letter counts
        return min(
            counts['b'], 
            counts['a'], 
            counts['l'] // 2, 
            counts['o'] // 2, 
            counts['n']
        )
