def solution(arr):
    n = 1
    
    arr.sort()
    while True:
        temp = arr[-1] * n
        n += 1

        flag = True
        for a in arr[:-1]:
            if temp % a != 0:
                flag = False
                break

        if flag:
            answer = temp
            break

    return answer


print(solution([2, 6, 8, 14]))
