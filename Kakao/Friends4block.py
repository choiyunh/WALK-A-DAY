def solution(m, n, board):
    answer = 0
    newBoard = []

    for i in range(n):
        temp = []
        for j in range(m - 1, -1, -1):
            temp.append(board[j][i])
        newBoard.append(temp)

    while True:
        boom = set()
        for i in range(1, n):
            for j in range(1, m):
                if newBoard[i - 1][j - 1] == newBoard[i - 1][j] == newBoard[i][j - 1] == newBoard[i][j] != -1:
                    boom |= {(i, j), (i - 1, j - 1), (i - 1, j), (i, j - 1)}
        if not boom:
            break
        for i, j in boom:
            newBoard[i][j] = 0
        for i in range(n):
            newBoard[i] = [item for item in newBoard[i] if item != 0]
            for k in range(m - len(newBoard[i])):
                newBoard[i].append(-1)
                answer += 1
    return answer


print(solution(4, 5, ["CCBDE", "AAADE", "AAABF", "CCBBF"]))
