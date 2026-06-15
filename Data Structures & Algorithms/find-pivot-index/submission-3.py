class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        left_sum = 0
        
        for i, num in enumerate(nums):
            # Calculate the right sum on the fly
            right_sum = total_sum - left_sum - num
            #print(i, num, left_sum, right_sum)
            if left_sum == right_sum:
                return i
                
            left_sum += num
            
        return -1
