class Solution:
    def balancedStringSplit(self, s: str) -> int:
        i = res = 0
        for j in range(2, len(s) + 1, 2):
            print(i, j)
            print(s[i:j])
            if s[i:j].count('L') == s[i:j].count('R'):
                res += 1
                i = j

        return res
