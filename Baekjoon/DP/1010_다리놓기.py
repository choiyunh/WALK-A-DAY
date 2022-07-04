def factorial(n):
    dp = [1, 1]

    for i in range(2, n + 1):
        dp.append(dp[i - 1] * i)
    return dp[-1]


# mCn
# m!/n!(m-n)!
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    print(factorial(m) // factorial(n) // (factorial(m - n)))


# 5C2
# 54321 / 21 321
