def solution(n):
    ans = 0

    while n:
        if n & 1:
            ans += 1
            n -= 1
        else:
            n //= 2
    return ans


print(solution(5000))
