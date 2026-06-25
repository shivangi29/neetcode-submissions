class Solution:
    def findLucky(self, arr: List[int]) -> int:
        tmp = [0] * 501
        for num in arr:
            tmp[num] += 1
        lar = -1
        for i in range(1, len(tmp)):
            if(tmp[i] == i):
                lar = i
        return lar