class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        res = []

        for n in nums:
            res.append(nums[n])

        return res