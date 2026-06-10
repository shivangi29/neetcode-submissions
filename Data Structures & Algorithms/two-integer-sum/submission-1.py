class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_arr = sorted(enumerate(nums), key = lambda x:x[1])
        i = 0 
        j = len(nums) - 1
        while i<j:
            sum = sorted_arr[i][1]+sorted_arr[j][1]
            if(sum == target):
                break
            elif(sum < target):
                i = i+1
            else:
                j = j-1

        return sorted([sorted_arr[i][0],sorted_arr[j][0]])