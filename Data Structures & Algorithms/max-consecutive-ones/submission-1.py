class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        return max(len(ones) for ones in "".join(map(str, nums)).split('0'))

            
            
        