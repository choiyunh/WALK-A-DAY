class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        res = 0

        for jewels in jewels:
            res += stones.count(jewels)

        return res