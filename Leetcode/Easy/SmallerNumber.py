class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        dic = [0] * (max(nums) + 1)

        for n in nums:
            dic[n] += 1

        return [sum(dic[:n]) for n in nums]