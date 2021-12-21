def solution(n):
    answer = 0
    for num in range(2, int((n-1)**0.5) + 1):
        if (n - 1) % num == 0:
            answer = num
            break

    if answer == 0:
        answer = n-1

    return answer