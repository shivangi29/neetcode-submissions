class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        map = set()
        for i in range(len(emails)):
            full = emails[i].split('@')
            local = (full[0].split('+')[0]).replace(".", "")
            domain = full[1].split('.com')[0]
            map.add(local+domain)
        print(map)
        return len(map)
            
