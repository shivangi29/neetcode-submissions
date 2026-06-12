class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        return [w1 for i, w1 in enumerate(words) if any(w1 in w2 for j, w2 in enumerate(words) if i != j)]
