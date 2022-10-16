# 2022/10/13 마법사 상어와 토네이도

def moveLeftRight():
    rst = [0, 0]
    for idx in range(-2, 3):
        if idx in {-1, 1}:
            tmp = int(a[x][y] * 0.07)
            rst[0] += tmp
            if 0 <= x + idx < n:
                a[x + idx][y] += tmp
            else:
                rst[1] += tmp
            tmp = int(a[x][y] * 0.1)
            rst[0] += tmp
            if 0 <= x + idx < n and 0 <= y + dy[dir] < n:
                a[x + idx][y + dy[dir]] += tmp
            else:
                rst[1] += tmp
            tmp = int(a[x][y] * 0.01)
            rst[0] += tmp
            if 0 <= x + idx < n and 0 <= y + (dy[dir] * -1) < n:
                a[x + idx][y + (dy[dir] * -1)] += tmp
            else:
                rst[1] += tmp
        elif idx in {-2, 2}:
            tmp = int(a[x][y] * 0.02)
            rst[0] += tmp
            if 0 <= x + idx < n:
                a[x + idx][y] += tmp
            else:
                rst[1] += tmp
        else:
            tmp = int(a[x][y] * 0.05)
            rst[0] += tmp
            if 0 <= y + (dy[dir] * 2) < n:
                a[x][y + (dy[dir] * 2)] += tmp
            else:
                rst[1] += tmp
    return rst


def moveUpDown():
    rst = [0, 0]
    for idx in range(-2, 3):
        if idx in {-1, 1}:
            tmp = int(a[x][y] * 0.07)
            rst[0] += tmp
            if 0 <= y + idx < n:
                a[x][y + idx] += tmp
            else:
                rst[1] += tmp
            tmp = int(a[x][y] * 0.1)
            rst[0] += tmp
            if 0 <= y + idx < n and 0 <= x + dx[dir] < n:
                a[x + dx[dir]][y + idx] += tmp
            else:
                rst[1] += tmp
            tmp = int(a[x][y] * 0.01)
            rst[0] += tmp
            if 0 <= y + idx < n and 0 <= x + (dx[dir] * -1) < n:
                a[x + (dx[dir] * -1)][y + idx] += tmp
            else:
                rst[1] += tmp
        elif idx in {-2, 2}:
            tmp = int(a[x][y] * 0.02)
            rst[0] += tmp
            if 0 <= y + idx < n:
                a[x][y + idx] += tmp
            else:
                rst[1] += tmp
        else:
            tmp = int(a[x][y] * 0.05)
            rst[0] += tmp
            if 0 <= x + (dx[dir] * 2) < n:
                a[x + (dx[dir] * 2)][y] += tmp
            else:
                rst[1] += tmp
    return rst


n = int(input())

a = []

for _ in range(n):
    a.append(list(map(int, input().split())))

x, y = n // 2, n // 2
dx, dy = [0, 1, 0, -1], [-1, 0, 1, 0]  # 좌 하 우 상
cnt = 0
answer = 0

while x >= 0 and y >= 0:
    dir = cnt % 4
    for i in range(cnt // 2 + 1):
        x, y = x + dx[dir], y + dy[dir]
        if dir in {0, 2}:  # 좌 우
            total, out = moveLeftRight()
            if 0 <= y + dy[dir] < n:
                a[x][y + dy[dir]] += a[x][y] - total
            else:
                answer += a[x][y] - total
            answer += out
            a[x][y] = 0
        elif dir in {1, 3}:
            total, out = moveUpDown()
            if 0 <= x + dx[dir] < n:
                a[x + dx[dir]][y] += a[x][y] - total
            else:
                answer += a[x][y] - total
            answer += out
            a[x][y] = 0
    cnt += 1
print(answer)
