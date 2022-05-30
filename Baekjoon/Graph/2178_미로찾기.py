N, M = map(int, input().split())

board = []

for i in range(N):
    board.append(list(map(int, input())))

stack = [[0, 0, 1]]
res = 1e9
dir = [[1, 0], [0, 1], [-1, 0], [0, -1]]
visited = [[0] * M for _ in range(N)]

# visited = [0 for _ in range(M)] * N -> 얕은 복사

while stack:
    x, y, cost = stack.pop()

    if x == N-1 and y == M-1:
        if res > cost:
            res = cost

    for d in dir:
        dx, dy = x + d[0], y + d[1]
        if 0 <= dx < N and 0 <= dy < M and board[dx][dy] and (not visited[dx][dy]):
            stack.append([dx, dy, cost + 1])
            visited[dx][dy] = 1

print(res)
