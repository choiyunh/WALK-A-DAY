def solution(n, computers):
    answer = 0
    com = [0] * n

    while 0 in com:
        stack = [com.index(0)]
        com[stack[0]] = 1

        while stack:
            node = stack.pop()

            for j in range(n):
                if com[j] == 0 and computers[node][j] == 1:
                    stack.append(j)
                    com[j] = 1
        answer += 1

    return answer


print(solution(4, [[1, 1, 0, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 0, 1, 1]]))