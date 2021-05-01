def solution(n, m):
    answer = [0]

    temp = 1
    while temp <= max(n, m):
        if n % temp == 0 and m % temp == 0:
            answer[0] = temp
        temp += 1

    temp = m
    while temp % n != 0:
        temp += m
    answer.append(temp)

    return answer


print(solution(2, 5))
