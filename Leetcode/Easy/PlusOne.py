"""
You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
"""


class Solution:
    def plusOne(self, digits: [int]) -> [int]:
        sum = 0
        for d in digits:
            sum = sum * 10 + d
        sum = str(sum + 1)

        rst = [s for s in sum]

        return rst
