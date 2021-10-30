class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        arr1 = nums[0:n]
        arr2 = nums[n:]
        res = []

        for a, b in zip(arr1, arr2):
            res += [a, b]

        return res