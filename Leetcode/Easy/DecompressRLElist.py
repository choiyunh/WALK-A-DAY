class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        res = []

        for i in range(0, len(nums), 2):
            res += [nums[i + 1]] * nums[i]

        return res