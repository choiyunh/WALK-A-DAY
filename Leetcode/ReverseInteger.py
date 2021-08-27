"""
Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

# Constraints:
- -2^31 <= x <= 2^31 - 1
"""


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1

        if x < 0:
            flag = -1
            x *= -1

        answer = 0
        while x != 0:
            answer = answer * 10 + x % 10

            if answer >= 2 ** 31:
                return 0
            x //= 10

        return answer * flag
