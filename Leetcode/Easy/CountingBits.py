class Solution:
    def countBits(self, n: int) -> [int]:
        res = []

        for i in range(n + 1):
            res.append(bin(i)[2:].count('1'))

        return res

    # def countBits(self, n: int) -> [int]:
    #     n += 1
    #     ans = [0, 1]
    #
    #     while len(ans) < n:
    #         ans = ans + [1 + x for x in ans]
    #
    #     return ans[:n]
    #
    # def countBits(self, n: int) -> [int]:
    #     res = [0] * (n + 1)
    #
    #     for i in range(1, n + 1):
    #         res[i] = res[i & (i - 1)] + 1
    #
    #     return res
