"""
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Given a roman numeral, convert it to an integer.
"""


class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """

        roman = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

        res, pre, sum = 0, 0, 0
        for i in range(len(s)):
            if roman[s[i]] > pre:
                sum = roman[s[i]] - sum
            elif roman[s[i]] == pre:
                sum += roman[s[i]]
            else:
                res += sum
                sum = roman[s[i]]

            if i == len(s) - 1:
                res += sum
            pre = roman[s[i]]

        return res
