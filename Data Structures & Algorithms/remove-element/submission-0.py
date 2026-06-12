class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i  = 0
        j = len(nums) - 1
        while(1):  
            while i<len(nums) and nums[i] != val:
                i += 1
            while j>=0 and nums[j] == val:
                j -= 1
            if(i>j):
                break
            if i<len(nums) and j>=0:
                nums[i] = nums[j]
                nums[j] = val
                i += 1
                j -= 1
        print(j+1, nums)
        return j + 1