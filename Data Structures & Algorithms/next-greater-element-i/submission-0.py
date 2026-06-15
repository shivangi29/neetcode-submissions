class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        greater_map = {}
        stack = []
        for num in nums2:
            while stack and num > stack[-1]:
                popped = stack.pop()
                greater_map[popped] = num

            stack.append(num)

        ans = []
        for num in nums1:
            if num in greater_map:
                ans.append(greater_map[num])
            else: ans.append(-1)
        return ans