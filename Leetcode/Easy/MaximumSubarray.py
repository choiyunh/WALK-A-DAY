"""
Given an integer array nums,
find the contiguous subarray (containing at least one number)
which has the largest sum and return its sum.

A subarray is a contiguous part of an array.
"""


class Solution:
    def maxSubArray(self, nums: [int]) -> int:
        dp = [nums[0]]

        for n in nums[1:]:
            dp.append(max(dp[-1] + n, n))

        return max(dp)


print(Solution.maxSubArray(Solution, [-2,1,-3,4,-1,2,1,-5,4]))
