import math

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        row_prev = [1] 
        if numRows == 1: return [row_prev]
        
        row_curr = [1, 1]
        ans = [row_prev, row_curr]
        if numRows == 2: return ans
        
        for i in range(3, numRows + 1):
            # 1. Start the new row with a left border boundary 1
            row_built = [1]
            
            # 2. Safely calculate the values up to the middle point
            for j in range(1, math.ceil(i / 2)):
                row_built.append(row_curr[j] + row_curr[j-1])
            
            # 3. Mirror the row to build the second half based on current row index 'i'
            if i % 2 == 0:
                # Even row number (e.g., 4 elements: 1, 3, 3, 1) -> mirror the whole thing
                # row_built is [1, 3], its reverse is [3, 1]
                full_row = row_built + row_built[::-1]
            else:
                # Odd row number (e.g., 5 elements: 1, 4, 6, 4, 1) -> drop the duplicate middle peak
                # row_built is [1, 4, 6], row_built[:-1] is [1, 4], its reverse is [4, 1]
                full_row = row_built + row_built[:-1][::-1]
            
            # 4. Save the full completed row to answer array and update row_curr tracking reference
            ans.append(full_row)
            row_curr = full_row
            
        return ans
