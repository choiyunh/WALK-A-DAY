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
        flag = True

        if x < 0:
            flag = False
            x *= -1
        cnt = len(str(x)) - 1

        answer = 0
        while x:
            answer += (x % 10) * (10 ** cnt)
            x //= 10
            cnt -= 1

        if -2 ** 31 <= answer <= 2 ** 31 - 1:
            if flag:
                return answer
            else:
                return answer * -1
        else:
            return 0
