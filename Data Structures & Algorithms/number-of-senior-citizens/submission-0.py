class Solution:
    def countSeniors(self, details: List[str]) -> int:
        count = 0
        for i in range(len(details)):
            age = (ord(details[i][11]) - 48) * 10 + ord(details[i][12]) - 48
            if age >60:
                count += 1
        return count