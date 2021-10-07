class Solution:
    cache = {}

    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n
        else:
            return self._climbStairs(n - 1) + self._climbStairs(n - 2)

    def _climbStairs(self, n: int):
        if n not in self.cache:
            self.cache[n] = self.climbStairs(n)
        return self.cache[n]

############################### USE BRUTE FORCE
# class Solution:
#     def climbStairs(self, n: int) -> int:
#         if n < 3:
#             return n
#         else :
#             return self.climbStairs(n-1) + self.climbStairs(n-2)
