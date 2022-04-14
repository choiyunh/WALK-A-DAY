N = int(input())

arr = map(int, input().split())
result = 0
for a in arr:
    error = 0
    if a > 1:
        for i in range(2, a):  # 2부터 n-1까지
            if a % i == 0:
                error += 1
        if error == 0:
            result += 1
print(result)
