class Solution:
    def xorOperation(self, n: int, start: int) -> int:
        nums = [start + 2 * i for i in range(n)]
        result = 0

        for num in nums:
            result ^= num

        return result


Solution.xorOperation(Solution, 5, 0)
