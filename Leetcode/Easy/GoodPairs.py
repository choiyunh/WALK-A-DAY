class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        dic = {}
        res = 0

        for n in nums:
            if n in dic:
                dic[n] += 1
            else:
                dic[n] = 1

        for k in dic:
            res += dic[k] * (dic[k] - 1) // 2

        return res
