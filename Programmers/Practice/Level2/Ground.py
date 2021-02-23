# def solution(land):
#     answer = 0
#
#     answer += max(land[0])
#     i = land[0].index(max(land[0]))
#
#     for l in land[1:]:
#         l[i] = 0
#         answer += max(l)
#         i = l.index(max(l))
#
#     return answer


def solution(land):
    # [1,2,3,5]
    maxIx = land[0].index(max(land[0]))

    maxFirst = land[0][maxIx]
    land[0][maxIx] = 0

    maxSecond = max(land[0])

    for l in land[1:]:
        for i in range(4):
            if i != maxIx:
                l[i] += maxFirst
            else:
                l[i] += maxSecond
        maxIx = l.index(max(l))
        maxFirst = l[maxIx]
        l[maxIx] = 0
        maxSecond = max(l)

    return maxFirst


print(solution([[1, 2, 3, 5], [5, 6, 7, 20], [4, 3, 2, 1]]))
