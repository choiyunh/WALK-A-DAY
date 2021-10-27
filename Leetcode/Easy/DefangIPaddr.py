class Solution:
    def defangIPaddr(self, address: str) -> str:
        res = ""

        for s in address:
            if s == '.':
                res += '[.]'
            else:
                res += s

        return res