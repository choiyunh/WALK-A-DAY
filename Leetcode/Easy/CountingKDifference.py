class Solution:
    def countKDifference(self, nums: List[int], k: int) -> int:
        result = 0

        for i in range(len(nums)):
            result += (nums[i + 1:].count(nums[i] + k) + nums[i + 1:].count(nums[i] - k))

        return result