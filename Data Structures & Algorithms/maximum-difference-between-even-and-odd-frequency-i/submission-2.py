class Solution:
    def maxDifference(self, s: str) -> int:
        count = Counter(s).values()
        even = min(x for x in count if x%2==0 and x!=0)
        odd = max(x for x in count if x%2 and x!=0)

        return odd - even
        