"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:
 1. Open brackets must be closed by the same type of brackets.
 2. Open brackets must be closed in the correct order.
"""


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """

        stack = []

        for c in s:
            if len(stack) == 0 and c in [')', '}', ']']:
                return False
            elif c in ['(', '{', '[']:
                stack.append(c)
            elif c == ')':
                if stack[-1] == '(':
                    stack.pop(-1)
                else:
                    return False
            elif c == '}':
                if stack[-1] == '{':
                    stack.pop(-1)
                else:
                    return False
            elif c == ']':
                if stack[-1] == '[':
                    stack.pop(-1)
                else:
                    return False

        if len(stack) == 0:
            return True
        else:
            return False
