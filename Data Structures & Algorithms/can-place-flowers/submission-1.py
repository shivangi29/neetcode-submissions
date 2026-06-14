class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        count = 0
        N = len(flowerbed)
        if(N == 1):
            if flowerbed[0] == 0:
                return n <= 1
            else: return n == 0
        if N > 1 and flowerbed[0] == 0 and flowerbed[1] == 0:
            flowerbed[0] = 1
            count = 1
        i = 0
        while i < N-1:
            if flowerbed[i] == 0 and flowerbed[i-1] == 0 and flowerbed[i+1] == 0:
                flowerbed[i] = 1
                count += 1
            if flowerbed[i] == 1:
                i += 2
            else:
                i+=1
        
        if N > 1:
            if(flowerbed[N-1] == 0 and flowerbed[N-2] == 0):
                count += 1

        return count >= n