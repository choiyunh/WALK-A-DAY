# 221125 n^2 배열 자르기

def solution(n, left, right):
    answer = []

    for i in range(left, right + 1):
        answer.append(max(i // n, i % n) + 1)
    return answer
