from collections import Counter
from typing import List

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        counts = Counter(arr)
        
        lucky = -1
        
        for num, frequency in counts.items():
            if num == frequency:
                lucky = max(lucky, num)
                
        return lucky
