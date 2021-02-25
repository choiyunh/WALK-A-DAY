def solution(a, b):
    arr = ['FRI', 'SAT', 'SUN', 'MON', 'TUE', 'WED', 'THU']
    sum = 0

    for i in range(1, a):
        if i == 2:
            sum += 29
            continue
        if (i < 8 and i & 1) or (i > 7 and not i & 1):
            sum += 31
        else:
            sum += 30
    sum += (b - 1)

    answer = arr[sum % 7]

    return answer


print(solution(12, 31))
