# def GetNumYaksu(n):
#     cnt = 0
#     flag = False
#     for i in range(1, int(n ** 0.5) + 1):
#         if i * i == n:
#             flag = True
#         if n % i == 0:
#             cnt += 1
#
#     if flag:
#         return cnt * 2 - 1
#     else:
#         return cnt * 2

def solution(left, right):
    answer = 0
    for n in range(left, right + 1):
        if int(n ** 0.5) == n ** 0.5:
            answer -= n
        else:
            answer += n
    return answer


print(solution(13, 17))
