"""
Given an array arr of integers,
check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :
- i != j
- 0 <= i, j < arr.length
- arr[i] == 2 * arr[j]

# Constraints:
- 2 <= arr.length <= 500
- -10^3 <= arr[i] <= 10^3
"""


class Solution(object):
    def checkIfExist(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        temp = set()
        temp.add(arr[0])
        for a in arr[1:]:
            if a * 2 in temp or a / 2.0 in temp:
                return True
            else:
                temp.add(a)

        return False
