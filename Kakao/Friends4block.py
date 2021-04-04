def solution(m, n, board):
    answer = 0
    print(board[5])
    newBoard = []
    for i in range(m):
        b = list(board[i])
        newBoard.append(b)

    boom = set()
    for i in range(1, m):
        for j in range(1, n):
            if board[i - 1][j - 1] == board[i - 1][j] == board[i][j - 1] == board[i][j]:
                boom |= {(i, j), (i - 1, j - 1), (i - 1, j), (i, j - 1)}
    print(boom)

    return answer


print(solution(6, 6, ["TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"]))
