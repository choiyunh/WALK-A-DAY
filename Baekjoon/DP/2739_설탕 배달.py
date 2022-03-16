N = int(input())

dp = [-1] * (N + 1)
dp[0] = 0
for n in range(3, N + 1):
    if dp[n - 3] != -1 and dp[n - 5] != -1:
        dp[n] = min(dp[n - 3], dp[n - 5]) + 1
    elif dp[n - 3] != -1:
        dp[n] = dp[n - 3] + 1
    elif dp[n - 5] != -1:
        dp[n] = dp[n - 5] + 1

print(dp[-1])
