def solution(n):
    answer = ''

    while n > 0:
        if n % 3 == 0:
            answer = '4' + answer
            n = (n // 3) - 1
        else:
            answer = str(n % 3) + answer
            n //= 3
            
    return answer


print(solution(10))
