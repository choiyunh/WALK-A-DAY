def solution(n):
    x = n ** 0.5

    if x == int(x):
        return int((x + 1) * (x + 1))
    else:
        return -1