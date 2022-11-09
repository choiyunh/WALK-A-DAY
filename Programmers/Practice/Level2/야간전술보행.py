# 221110 야간 전술보행

def solution(distance, scope, times):
    answer = distance
    for i in range(len(scope)):
        if scope[i][0] > scope[i][1]:
            scope[i].sort()
        for j in range(scope[i][0], scope[i][1] + 1):
            if 1 <= (j % (times[i][0] + times[i][1])) < times[i][0] + 1:
                if answer > j:
                    answer = j
    return answer
