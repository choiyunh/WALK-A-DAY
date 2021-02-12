def solution(num):
    answer = 0

    while num != 1:
        answer += 1
        if num & 1:
            num *= 3
            num += 1
        else:
            num //= 2

    if answer >= 500:
        return -1
    return answer


print(solution(6))
