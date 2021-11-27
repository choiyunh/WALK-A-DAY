# 월간 코드 챌린지 시즌3
# 없는 숫자 더하기

def solution(numbers):
    answer = 0
    numbers.sort()

    target = 0
    i = 0

    while i < len(numbers):
        if numbers[i] == target:
            i += 1
            target += 1
        else:
            answer += target
            target += 1
    while target < 10:
        answer += target
        target += 1

    return answer


# 45 - sum(nunmbers) ..........