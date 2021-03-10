def solution(nums):
    answer = 0
    cnt = len(nums) // 2
    temp = []

    for n in nums:
        if not cnt:
            break
        if not temp or n not in temp:
            answer += 1
            cnt -= 1
        temp.append(n)

    return answer


print(solution([3, 3, 3, 3]))
