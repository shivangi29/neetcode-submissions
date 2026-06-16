class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        map = {}

        for st in arr:
            if st in map:
                map[st] += 1
            else:
                map[st] = 1
        
        for st in arr:
            if(map[st] == 1):
                k -= 1
                if k == 0:
                    return st
        return ""
            
