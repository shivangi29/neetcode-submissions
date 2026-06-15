class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_sum = nums[0]
        sum = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                sum+=nums[i]
            else:
                sum = nums[i]
        
            max_sum = max(max_sum, sum)
        return max_sum