from itertools import product


def solution(grid):
    answer = ""
    row, col = len(grid), len(grid[0])
    check = [[False for _ in range(col)] for _ in range(row)]

    r, c = 0, 0
    while r < row:
        if check[r][c]:
            c += 1
            if c >= col:
                r += 1
                c = 0
            continue
        x = grid[r][c]
        flag = False
        for k in range(1, min(row - r + 1, col - c + 1)):
            dirs = list(product(range(k), repeat=2))
            for dx, dy in dirs:
                if (check[r + dx][c + dy]) or (grid[r + dx][c + dy] != x):
                    flag = True
                    break
            if flag:
                break
        answer += x
        if flag:
            k -= 1
        dirs = list(product(range(k), repeat=2))
        if k > 1:
            answer += str(k)
        for dx, dy in dirs:
            check[r + dx][c + dy] = True
        c += 1
        if c >= col:
            r += 1
            c = 0

    return answer
