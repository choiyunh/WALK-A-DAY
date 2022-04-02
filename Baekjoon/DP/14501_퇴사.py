N = int(input())
T = [0] * (N)
P = [0] * (N)
dp = [0] * (N + 1)

for i in range(N):
    a, b = input().split()
    T[i] = (int(a))
    P[i] = (int(b))

for i in range(N - 1, -1, -1):
    if i + T[i] <= N:
        dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]])
    else:
        dp[i] = dp[i+1]
print(dp[0])
