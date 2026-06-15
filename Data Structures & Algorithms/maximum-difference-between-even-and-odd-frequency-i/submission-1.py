class Solution:
    def maxDifference(self, s: str) -> int:
        count = [0] * 26
        for ch in s:
            count[ord(ch) - ord('a')] += 1
        even = min(x for x in count if x%2==0 and x!=0)
        odd = max(x for x in count if x%2 and x!=0)

        return odd - even
        