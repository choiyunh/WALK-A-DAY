T = int(input())

for _ in range(T):
    num, s = input().split()
    result = ""
    num = int(num)
    idx = 0
    for i in range(num * len(s)):
        if i != 0 and i % num == 0:
            idx += 1
        if idx == len(s):
            break
        result += s[idx]
    print(result)
