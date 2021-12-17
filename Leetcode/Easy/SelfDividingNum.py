class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result = []
        for num in range(left, right + 1):
            if '0' in str(num):
                continue
            strNum = str(num)
            cnt = 0
            for c in str(num):
                if num % int(c) == 0:
                    cnt += 1

            if cnt == len(strNum):
                result.append(num)

        return result
