def solution(n):
    dp = [0, 1]

    for i in range(2, n + 1):
        dp.append(dp[i - 1] + dp[i - 2])

    answer = dp[n] % 1234567
    return answer


print(solution(5))
