"""
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
"""


class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        strs.sort(key=len)

        rst = ""
        for j in range(len(strs[0])):
            cur = strs[0][j]
            for i in range(1, len(strs)):
                if strs[i][j] != cur:
                    return rst
            rst += cur
        return rst


print(Solution.longestCommonPrefix(Solution, ["flower", "flow", "flight"]))
