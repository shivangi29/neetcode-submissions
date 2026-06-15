class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        dec_len = 1
        inc_len = 1
        max_inc = 1
        max_dec = 1

        for i in range(1, len(nums)):
            if nums[i] > nums[i-1]:
                inc_len += 1
                max_dec = max(max_dec, dec_len)
                dec_len = 1
            elif nums[i] < nums[i-1]:
                dec_len += 1
                max_inc = max(max_inc, inc_len)
                inc_len = 1
            else:
                max_dec = max(max_dec, dec_len)
                max_inc = max(max_inc, inc_len)
                dec_len = 1
                inc_len = 1
        return max(max(max_dec, dec_len), max(max_inc, inc_len))