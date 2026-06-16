class Solution:
    def kthDistinct(self, arr: List[str], k: int) -> str:
        map = {}

        for st in arr:
            if st in map:
                map[st] += 1
            else:
                map[st] = 1
        
        for st, count in map.items():
            if(count == 1):
                k -= 1
                if k == 0:
                    return st
        return ""
            
