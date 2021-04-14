def solution(board):
    answer = 0

    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 1:
                x, y = j + 1, i + 1
                while board[i][x] != 0 and board[y][j] != 0 and x < len(board[0]) and y < len(board):
                    x, y = x + 1, y + 1

                while board[]
    return answer


print(solution([[0, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [0, 0, 1, 0]]))
