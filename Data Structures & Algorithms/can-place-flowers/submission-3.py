class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        if n == 0:
            return True
            
        for i in range(len(flowerbed)):
            if flowerbed[i] == 0:
                # Check left: True if we are at index 0 OR left is empty
                left_empty = (i == 0 or flowerbed[i - 1] == 0)
                # Check right: True if we are at last index OR right is empty
                right_empty = (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0)
                
                if left_empty and right_empty:
                    flowerbed[i] = 1
                    n -= 1
                    if n == 0:
                        return True
                        
        return n <= 0
