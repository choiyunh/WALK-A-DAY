def solution(arr1, arr2):
    #answer = [[0] * len(arr2)] * len(arr1)
    #answer = [[0 for col in range(len(arr2[0]))] for row in range(len(arr1))]

    answer = [[0] * 2] * 3
    print(answer)
    answer[2][0] = 5

    a=[0,0]
    b=[]
    b.append(a)
    b.append(a)
    b.append(a)
    b[0][0]=5
    print(b)
    return answer


print(solution([[1, 4], [3, 2], [4, 1]],[[3, 3], [3, 3]]))