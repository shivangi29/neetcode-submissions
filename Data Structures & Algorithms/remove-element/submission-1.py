class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums) - 1
        
        # Run until the two pointers cross
        while i <= j:
            # Move i forward until we find a target value to remove
            while i <= j and nums[i] != val:
                i += 1
            # Move j backward until we find a valid value to save
            while i <= j and nums[j] == val:
                j -= 1
                
            # If they haven't crossed yet, swap the elements
            if i < j:
                nums[i] = nums[j]
                nums[j] = val
                i += 1
                j -= 1
                
        # 'i' naturally stops at the count of elements that are NOT equal to val
        return i
