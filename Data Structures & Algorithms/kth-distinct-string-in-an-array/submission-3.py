class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        map = Counter(arr)
        
        for st in arr:
            if(map[st] == 1):
                k -= 1
                if k == 0:
                    return st
        return ""
            
