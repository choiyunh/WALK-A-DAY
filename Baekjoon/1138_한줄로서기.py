N = int(input())
arr = list(map(int, input().split()))
result = [0] * N

result[arr[0]] = 1

for i in range(1, N):
    for j in range(N):
        if result[j] == 0 and result[:j].count(0) == arr[i]:
            result[j] = i + 1
            break
print(*result)
