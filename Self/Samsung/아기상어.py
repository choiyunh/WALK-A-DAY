# 2022/10/12 아기상어

from collections import deque


def eatFish(sharkSize):
    dist = [[0 for _ in range(n)] for _ in range(n)]
    visited = [[False for _ in range(n)] for _ in range(n)]
    dx, dy = [0, 0, 1, -1], [1, -1, 0, 0]
    queue = deque()
    queue.append((x, y))
    visited[x][y] = True

    candidate = []
    while queue:
        curX, curY = queue.popleft()

        for i in range(4):
            nx, ny = curX + dx[i], curY + dy[i]

            if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                if board[nx][ny] <= sharkSize:
                    queue.append((nx, ny))
                    visited[nx][ny] = True
                    dist[nx][ny] = dist[curX][curY] + 1

                    if board[nx][ny] < sharkSize and 1 <= board[nx][ny] <= 6:
                        candidate.append((nx, ny, dist[nx][ny]))
    return sorted(candidate, key=lambda x: (-x[2], -x[0], -x[1]))


n = int(input())

board = []
for _ in range(n):
    board.append(list(map(int, input().split())))
x, y = 0, 0
for i in range(n):
    for j in range(n):
        if board[i][j] == 9:
            x, y = i, j

sharkSize = 2
answer = 0
cntEat = 0
while True:
    result = eatFish(sharkSize)
    if len(result) == 0:
        break
    cntEat += 1

    if cntEat == sharkSize:
        cntEat = 0
        sharkSize += 1
    nx, ny, dist = result.pop()
    answer += dist
    board[x][y], board[nx][ny] = 0, 0

    x, y = nx, ny
print(answer)
