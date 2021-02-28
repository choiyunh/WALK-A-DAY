def solution(s):
    answer = ''
    arr = []

    for a in s.split():
        arr.append(int(a))

    answer += str(min(arr)) + ' ' + str(max(arr))
    return answer


print(solution('-1 -2 -3 -4'))
