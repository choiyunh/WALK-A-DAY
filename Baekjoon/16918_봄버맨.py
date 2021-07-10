R, N, C = map(int, input().split())

grid = []
for i in range(R):
    tmp = list(input())
    grid.append(tmp)

pos = []
dic = [(1, 0), (-1, 0), (0, 1), (0, -1)]
cnt = 2
while cnt <= C:
    if not cnt & 1:
        pos = []
        for i in range(R):
            for j in range(N):
                if grid[i][j] == 'O':
                    pos.append((i, j))
                else:
                    grid[i][j] = 'O'
    else:
        for p in pos:
            grid[p[0]][p[1]] = '.'
            for d in dic:
                b = (p[0] + d[0], p[1] + d[1])
                if (0 <= b[0] < R) and (0 <= b[1] < N):
                    grid[b[0]][b[1]] = '.'
    cnt += 1

for g in grid:
    print(''.join(g))