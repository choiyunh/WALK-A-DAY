class Solution:
    def diStringMatch(self, s: str) -> List[int]:
        minNum, maxNum = 0, len(s)
        res = []

        for c in s:
            if c == 'I':
                res.append(minNum)
                minNum += 1
            elif c == 'D':
                res.append(maxNum)
                maxNum -= 1
        res.append(minNum)

        return res