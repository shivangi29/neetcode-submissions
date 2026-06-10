class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        max = 0
        n = len(nums)
        for i in range(n):
            count = 0
            while(i < n and nums[i] == 1):
                i += 1
                count += 1
            if(count > max):
                max = count
        return max

            
            
        