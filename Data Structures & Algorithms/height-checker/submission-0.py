class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        arr = [0]*101
        for num in heights:
            arr[num] += 1
        curr = 0
        ans = 0
        #print(arr)
        for i in range(len(arr)):
            if arr[i] != 0:
                count = arr[i]
                #print(count)
                while count:
                    #print(curr)
                    if(heights[curr] != i):
                        ans += 1
                    curr += 1
                    count -= 1
                
        return ans
            
        