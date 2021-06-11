def solution(N, road, K):
    answer = 0

    d = [[0] * (N + 1) for i in range(N + 1)]

    for r in road:
        d[r[0]][r[1]] = r[2]
    print(d)

    return answer


print(solution(5, [[1, 2, 1], [2, 3, 3], [5, 2, 2], [1, 4, 2], [5, 3, 1], [5, 4, 2]], 3))
