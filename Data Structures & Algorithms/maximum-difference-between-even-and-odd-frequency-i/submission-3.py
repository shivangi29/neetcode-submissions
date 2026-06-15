class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s).values()
        return max(x for x in count if x%2) - min(x for x in count if x%2==0)

        
        