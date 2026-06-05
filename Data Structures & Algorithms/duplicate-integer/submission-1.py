class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set_empty = set()
        for i in nums:
            if i in set_empty:
                return True
            set_empty.add(i)
        return False
