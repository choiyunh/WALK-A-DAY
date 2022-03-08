N = int(input())

distances = list(map(int, input().split()))
prices = list(map(int, input().split()))

result = 0
i = 0
while i < N - 1:
    j = i + 1
    while prices[i] < prices[j]:
        result += distances[j] * prices[i]
        j += 1
        if j == N - 1:
            break
    result += distances[i] * prices[i]
    i = j

print(result)
