class Solution:
    def generate(self, numRows: int) -> [[int]]:
        result = []

        for row in range(numRows):
            result.append([1] * (row + 1))

        for i in range(2, numRows):
            for j in range(1, i):
                result[i][j] = result[i - 1][j - 1] + result[i - 1][j]

        return result
