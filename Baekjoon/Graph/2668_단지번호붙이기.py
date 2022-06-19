n = int(input())
board = [list(map(int, input())) for _ in range(n)]
dx, dy = [-1, 1, 0, 0], [0, 0, -1, 1]
result = []
count = 0


def dfs(x, y):
    if x < 0 or x >= n or y < 0 or y >= n:
        return False

    if board[x][y] == 1:
        global count
        count += 1
        board[x][y] = 0
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            dfs(nx, ny)
        return True
    return False


for i in range(n):
    for j in range(n):
        if dfs(i, j):
            result.append(count)
            count = 0
result.sort()
print(len(result))
print(*result, sep='\n')
