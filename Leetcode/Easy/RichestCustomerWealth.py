class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        res = 0
        for a in accounts:
            if res < sum(a):
                res = sum(a)

        return res