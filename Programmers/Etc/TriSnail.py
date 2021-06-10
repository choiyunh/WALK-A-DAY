def solution(n):
    snail = [[0 for i in range(n)] for i in range(n)]

    # 삼각 달팽이에 채울 숫자의 최대값
    maxNum = n * (n // 2 + 1)
    if not n & 1:
        maxNum -= (n // 2)

    top, bottom, left, right = 0, n - 1, 0, n - 1
    flag = 0
    row, col = -1, 0
    for i in range(1, maxNum + 1):
        if flag == 0:
            row += 1
            if row == bottom:
                flag = 1
                top += 1
                left += 1
        elif flag == 1:
            col += 1
            if col == right:
                flag = 2
                bottom -= 1
                right -= 1
        elif flag == 2:
            row -= 1
            col -= 1
            if row == top or col == left:
                flag = 0
                top += 1
                right -= 1
        snail[row][col] = i

    answer = []
    for i in range(n):
        for j in range(n):
            if snail[i][j]:
                answer.append(snail[i][j])

    return answer


print(solution(5))
