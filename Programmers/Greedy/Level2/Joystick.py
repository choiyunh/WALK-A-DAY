def solution(name):
    answer = 0
    arr = []

    for n in name:
        controlCount = ord(n) - 65
        if controlCount > 13:
            arr.append(26 - controlCount)
        else:
            arr.append(controlCount)
    i = 0
    while True:
        answer += arr[i]
        arr[i] = 0
        if sum(arr) == 0:
            break

        left, right = 1, 1
        while arr[i - left] == 0:
            left += 1
        while arr[i + right] == 0:
            right += 1
        answer += left if left <= right else right
        i += -left if left < right else right

    return answer


print(solution('ABABAAAAAAABA'))
