class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        ans = []
        for row in grid:
            for num in row:
                num = abs(num)
                idx = num - 1
                i = idx // n
                j = idx % n
                if grid[i][j] > 0:
                    grid[i][j] = -grid[i][j]
                else:
                    ans.append(num)

        for i in range(n):
            for j in range(n):
                if(grid[i][j] > 0):
                    ans.append(n*i + j+1)
        return ans
        
