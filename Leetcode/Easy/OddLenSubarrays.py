class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        sumSubarr = 0

        for oddLen in range(1, len(arr) + 1, 2):
            for i in range(len(arr)):
                subArr = arr[i:i + oddLen]

                if len(subArr) == oddLen:
                    sumSubarr += sum(subArr)

        return sumSubarr
