def solution(board):
    answer = 0

    if len(board) == 1:
        return int(1 in board[0])
    elif len(board[0]) == 1:
        return int([1] in board)

    for i in range(1, len(board)):
        for j in range(1, len(board[0])):
            if board[i][j]:
                board[i][j] = min(board[i - 1][j], board[i][j - 1], board[i - 1][j - 1]) + 1
                answer = max(board[i][j], answer)

    return answer * answer


print(solution([[0, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [0, 0, 1, 0]]))
print(solution([[0, 1, 1, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]])) # ???
