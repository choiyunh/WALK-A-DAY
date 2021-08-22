class Solution(object):
    def duplicateZeros(self, arr):
        """
        :type arr: List[int]
        :rtype: None Do not return anything, modify arr in-place instead.
        """
        answer = []

        for a in arr:
            if not a:
                answer.append(a)
            answer.append(a)

        for i in range(len(arr)):
            arr[i] = answer[i]
