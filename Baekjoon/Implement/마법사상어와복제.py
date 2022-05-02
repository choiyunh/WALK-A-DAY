def moveFish(map_):
    result = [[[] for _ in range(4)] for _ in range(4)]
    for x in range(4):
        for y in range(4):
            while map_[x][y]:
                d = map_[x][y].pop()
                for i in range(d, d - 8, -1):
                    i %= 8
                    nx, ny = x + fishDir[i][0], y + fishDir[i][1]
                    if (nx, ny) != shark and 0 <= nx < 4 and 0 <= ny < 4 and not smell[nx][ny]:
                        result[nx][ny].append(i)
                        break
                else:
                    result[x][y].append(d)
    return result


def moveShark(s):
    x, y = s
    q = []
    q.append((x, y, set(), '', 0))

    for _ in range(3):
        for _ in range(len(q)):
            x, y, visited, num, cnt = q.pop(0)
            for i in range(1, 5):
                nx, ny = x + sharkDir[i][0], y + sharkDir[i][1]
                if 0 <= nx < 4 and 0 <= ny < 4:
                    if (nx, ny) in visited:
                        q.append((nx, ny, visited, num + str(i), cnt))
                    else:
                        q.append(
                            (nx, ny, visited | {(nx, ny)}, num + str(i), cnt + len(copy[nx][ny])))
    q.sort(key=lambda x: (x[4], -int(x[3])))
    x, y, visited, num, cnt = q[-1]
    for i, j in visited:
        if copy[i][j]:
            copy[i][j].clear()
            smell[i][j] = 3
    return (x, y)


M, S = map(int, input().split())
fishes = list(tuple(map(lambda x: int(x) - 1, input().split()))
              for _ in range(M))
fishDir = [(0, -1), (-1, -1), (-1, 0), (-1, 1),
           (0, 1), (1, 1), (1, 0), (1, -1)]
sharkDir = [0, (-1, 0), (0, -1), (1, 0), (0, 1)]
map_ = [[[] for _ in range(4)] for _ in range(4)]

for x, y, d in fishes:
    map_[x][y].append(d)

shark = tuple(map(lambda x: int(x) - 1, input().split()))
smell = [[0] * 4 for _ in range(4)]

for _ in range(S):
    # 1
    copy = [[j[:] for j in i] for i in map_]

    # 2
    copy = moveFish(copy)

    # 3
    shark = moveShark(shark)

    # 4
    for i in range(4):
        for j in range(4):
            if smell[i][j]:
                smell[i][j] -= 1
    # 5
    for i in range(4):
        for j in range(4):
            map_[i][j] += copy[i][j]

answer = 0
for i in range(4):
    for j in range(4):
        answer += len(map_[i][j])

print(answer)
