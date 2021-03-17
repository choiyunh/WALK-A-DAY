def solution(arr):
    arr.pop(arr.index(min(arr)))
    print(arr)
    if not arr:
        return [-1]

    return arr


solution([4,3,2,1])