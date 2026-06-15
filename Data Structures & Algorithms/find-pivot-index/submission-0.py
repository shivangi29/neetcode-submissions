class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return 0;
        f_sum = [0] * (n)
        b_sum = [0] * (n)
        
        for i in range(1, n):
            f_sum[i] = f_sum[i-1] + nums[i-1]
        for i in range(n-2, -1, -1):
            #print(i)
            b_sum[i] = b_sum[i+1] + nums[i+1]
        #print(f_sum, b_sum)
        for i in range(n):
            if f_sum[i] == b_sum[i]:
                return i

        return -1

