def solution(arr1, arr2):
    answer = []

    for a, b in zip(arr1, arr2):
        tmp = []
        for aa, bb in zip(a, b):
            tmp.append(aa + bb)
        answer.append(tmp)

    return answer


print(solution([[1, 2], [2, 3]], [[3, 4], [5, 6]]))
