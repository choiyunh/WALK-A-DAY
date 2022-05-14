def solution(n):
    sqrtN = n ** 0.5

    if sqrtN % 1 != 0:
        return -1
    return (sqrtN + 1) ** 2
