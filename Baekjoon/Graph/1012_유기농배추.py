from collections import deque

T = int(input())

for _ in range(T):
    M, N, K = map(int, input().split())

    board = [[0] * M for _ in range(N)]

    for _ in range(K):
        X, Y = map(int, input().split())
        board[Y][X] = 1

    result = 0
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]
    queue = deque([])
    for i in range(0, N):
        for j in range(0, M):
            if board[i][j] == 1:
                queue.append([i, j])
                board[i][j] = -1
                while True:
                    y, x = queue.pop()
                    for d in range(4):
                        nX = dx[d] + x
                        nY = dy[d] + y
                        if 0 <= nX < M and 0 <= nY < N:
                            if board[nY][nX] == 1:
                                board[nY][nX] = -1
                                queue.append([nY, nX])

                    if not queue:
                        result += 1
                        break
    print(result)
