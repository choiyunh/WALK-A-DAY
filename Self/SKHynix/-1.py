from itertools import permutations


def solution(seat):
    row, col = len(seat), len(seat[0])
    answer = 0
    direction = []
    for i in range(row):
        for j in range(col):
            if seat[i][j] == 'M':
                direction = [(-2, 0), (-1, 0), (1, 0), (2, 0),
                             (0, -2), (0, -1), (0, 1), (0, 2),
                             (-1, -1), (-1, 1), (1, -1), (1, 1)]
            elif seat[i][j] == 'N':
                direction = [(-3, 0), (-2, 0), (-1, 0), (1, 0), (2, 0), (3, 0),
                             (0, -3), (0, -2), (0, -1), (0, 1), (0, 2), (0, 3),
                             (-2, -1), (-2, 1), (-1, -2), (-1, -1), (-1, 1), (-1, 2),
                             (2, -1), (2, 1), (1, -2), (1, -1), (1, 1), (1, 2)]
            if seat[i][j] in ['M', 'N']:
                for dx, dy in direction:
                    if 0 <= i + dx < row and 0 <= j + dy < col:
                        if seat[i + dx][j + dy] == 'C':
                            answer += 1
                            break
    return answer


print(solution([['0', 'C', 'M', 'C', '0'],
                ['0', '0', 'M', 'N', '0'],
                ['0', '0', 'N', '0', '0'],
                ['0', '0', '0', '0', '0'],
                ['0', '0', '0', '0', 'M']]))
