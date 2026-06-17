class NumArray:
    
    def __init__(self, nums: List[int]):
        self.matrix = []
        for i in range(len(nums)):
            tmp = [0]*len(nums)
            for j in range(i, len(nums)):
                tmp[j] += (tmp[j-1] if j>i else 0) + nums[j]
            self.matrix.append(tmp)
    
    def sumRange(self, left: int, right: int) -> int:
        return self.matrix[left][right]        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)