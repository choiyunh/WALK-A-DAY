class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        res = 0
        for oper in operations:
            if '+' in oper:
                res += 1
            elif '-' in oper:
                res -= 1

        return res