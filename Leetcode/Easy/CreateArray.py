class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        res = []

        for i in range(len(index)):
            res = res[:index[i]] + [nums[i]] + res[index[i]:]

        return res