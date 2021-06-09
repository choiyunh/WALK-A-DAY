def solution(n):
    snail = [[0 for i in range(n)] for i in range(n)]

    num = 1
    flag = 0
    minRow = 1
    maxRow = n - 1
    maxCol = n - 1
    row = 0
    col = 0
    while True:
        if flag == 0:
            if snail[row][col] != 0:
                break
            snail[row][col] = num
            if row == maxRow:
                flag = 1
                maxRow -= 1
                col += 1
            else:
                row += 1
        elif flag == 1:
            if snail[row][col] != 0:
                break
            snail[row][col] = num
            if col == maxCol:
                flag = 2
                maxCol -= 1
                row -= 1
                col -= 1
            else:
                col += 1
        elif flag == 2:
            if snail[row][col] != 0:
                break
            snail[row][col] = num
            if row == minRow:
                flag = 0
                minRow += 1
                maxCol -= 1
                row += 1
            else:
                row -= 1
                col -= 1
        num += 1
    answer = []
    for r in snail:
        for c in r:
            if c:
                answer.append(c)
    return answer


print(solution(6))
