from re import T


n = int(input())
time = sorted(list(map(int, input().split())))

result = 0
for i in range(len(time)):
    result += sum(time[:i + 1])
print(result)
