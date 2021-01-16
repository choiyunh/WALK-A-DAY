def solution(citations):
    num = len(citations)
    citations.sort()
    for i in range(num):
        if citations[i] >= num - i:
            return num - i
    return 0


print(solution([4, 0, 1, 6, 5]))