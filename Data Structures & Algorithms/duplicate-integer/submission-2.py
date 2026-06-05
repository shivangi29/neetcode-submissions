class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        set_unique = set(nums)
        return len(set_unique) < len(nums) 
