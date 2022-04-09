n = int(input())
result = [0] * (n + 1)

for i in range(n + 1):
    if i == 0:
        result[i] = 0
    elif i == 1:
        result[i] = 1
    else:
        result[i] = result[i-2] + result[i-1]
print(result[-1])
