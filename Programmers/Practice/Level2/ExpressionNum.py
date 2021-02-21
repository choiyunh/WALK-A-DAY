def solution(n):
    answer = 0

    tempSum = 0
    startNum = 1
    opNum = startNum

    while opNum <= n:
        tempSum += opNum
        if tempSum >= n:
            if tempSum == n:
                answer += 1
            startNum += 1
            opNum = startNum
            tempSum = 0
        else:
            opNum += 1
    return answer


print(solution(15))
