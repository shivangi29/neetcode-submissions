class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set = []
        for i in nums:
            if i in set:
                return True
            set.append(i)
        return False
