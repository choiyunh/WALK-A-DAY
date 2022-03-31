A, B, C, M = map(int, input().split())

day = 0

result = 0
count = 0

if A > M:
    print(0)
else:
    while day != 24:
        day += 1
        if count + A <= M:
            result += B
            count += A
        else:
            if count - C >= 0:
                count -= C
            else:
                count = 0

    print(result)
