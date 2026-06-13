class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        m = len(s)
        n = len(t)
        if m!=n: return False
        map_s = {}
        map_t = {}
        for i in range(len(s)):
            if s[i] in map_s:
                #print("0",s[i], map_s[s[i]])
                if map_s[s[i]] != t[i]:
                    return False
            
            else: 
                if(t[i] in map_t):
                    return False
                map_s[s[i]] = t[i]
                map_t[t[i]] = s[i]
            #print("1",s[i], my_map[s[i]])

        return True


        