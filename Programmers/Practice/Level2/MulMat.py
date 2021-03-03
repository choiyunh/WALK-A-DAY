def solution(arr1, arr2):
    answer = [[0 for col in range(len(arr2[0]))] for row in range(len(arr1))]
    # print(answer)

    for i in range(len(arr1)):
        for j in range(len(arr2[0])):
            for k in range(len(arr1[0])):
                answer[i][j] += arr1[i][k] * arr2[k][j]
    return answer


print(solution([[1, 1], [1, 1], [1, 1], [1, 1]],
               [[1, 1, 1, 1], [1, 1, 1, 1]]))
