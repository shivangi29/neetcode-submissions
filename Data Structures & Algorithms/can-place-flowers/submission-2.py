class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        # Add 0 to both sides to handle edges easily
        padded_bed = [0] + flowerbed + [0]
        
        for i in range(1, len(padded_bed) - 1):
            # Check if left, current, and right plots are all empty
            if padded_bed[i-1] == 0 and padded_bed[i] == 0 and padded_bed[i+1] == 0:
                padded_bed[i] = 1  # Plant the flower
                n -= 1             # One less flower needed
                
            # Early exit if we already planted enough flowers
            if n <= 0:
                return True
                
        return n <= 0
