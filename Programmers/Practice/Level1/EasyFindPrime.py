import math


def solution(n):
    answer = 0
    flag = True

    for n in range(2, n + 1):
        for nn in range(2, int(math.sqrt(n)) + 1):
            if n % nn == 0:
                flag = False
                break
        if flag:
            answer += 1
        flag = True
    return answer


print(solution(2))
