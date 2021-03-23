def convert(num, n):
    result = ''
    if num == 0:
        return '0'
    while num:
        if num % n >= 10:
            result = chr(55 + num % n) + result
        else:
            result = str(num % n) + result
        num //= n
    return result


def solution(n, t, m, p):
    answer = ''
    num = 0
    temp = ''
    while len(temp) < t * m:
        temp += convert(num, n)
        num += 1
    temp = temp[:t * m]

    for i in range(p - 1, len(temp), m):
        answer += temp[i]

    return answer


print(solution(2, 4, 2, 1))
