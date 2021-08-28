"""
Given an integer x, return true if x is palindrome integer.
An integer is a palindrome when it reads the same backward as forward.
For example, 121 is palindrome while 123 is not.
"""


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False

        s = str(x)
        i, j = 0, len(s) - 1

        while i < j:
            if s[i] != s[j]:
                return False
            i, j = i + 1, j - 1
        return True


print(Solution.isPalindrome(Solution, 123321))
