def solution(n):
    answer = []
    reverseStr = reversed(str(n))

    for c in reverseStr:
        answer.append(int(c))
    return answer