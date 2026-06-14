class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        maj = nums[0]
        for i in range(len(nums)):
            if count == 0:
                maj = nums[i]

            if nums[i] != maj:
                count -= 1
            else:
                count += 1
        return maj