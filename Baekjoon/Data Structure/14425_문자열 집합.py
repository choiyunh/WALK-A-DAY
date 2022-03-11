N, M = map(int, input().split())

strs = {input() for _ in range(N)}

result = 0
for _ in range(M):
    if input() in strs:
        result += 1

print(result)
