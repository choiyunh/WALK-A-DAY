def solution(board, moves):
    answer = 0
    stack = []
    for m in moves:
        for row in board:
            if row[m - 1]:
                if stack and stack[-1] == row[m - 1]:
                    stack.pop()
                    answer += 2
                else:
                    stack.append(row[m - 1])
                row[m - 1] = 0
                break
    return answer


solution([[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]],
         [1, 5, 3, 5, 1, 2, 1, 4])
