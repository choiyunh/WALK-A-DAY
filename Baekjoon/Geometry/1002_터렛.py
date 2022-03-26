N = int(input())

for _ in range(N):
    x1, y1, r1, x2, y2, r2 = list(map(int, input().split()))

    dist = ((x1 - x2)**2 + (y1 - y2)**2) ** (1/2)

    if dist == 0:
        if r1 == r2:
            print(-1)
        else:
            print(0)
    else:
        if r1+r2 == dist or abs(r2-r1) == dist:
            print(1)
        elif ((abs(r1-r2) < dist) and (dist < r1+r2)):
            print(2)
        else:
            print(0)
