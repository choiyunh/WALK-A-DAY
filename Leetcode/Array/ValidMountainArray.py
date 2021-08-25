"""
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

# Constraints:
- 1 <= arr.length <= 104
- 0 <= arr[i] <= 104
"""


class Solution(object):
    def validMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        increase = True

        for i in range(len(arr) - 1):
            if i == 0 and arr[i + 1] <= arr[i]:
                return False
            if increase:
                if arr[i + 1] > arr[i]:
                    continue
                elif arr[i + 1] == arr[i]:
                    return False
                else:
                    increase = False
            else:
                if arr[i + 1] >= arr[i]:
                    return False
        if increase:
            return False
        else:
            return True
