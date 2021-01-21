def solution(number, k):
    answerList = []

    for i in range(len(number) - 1):
        answerList.append(number[i])
        i += 1
        while len(answerList) > 0 and number[i] > answerList[-1] and k > 0:
            answerList.pop()
            k -= 1
    answerList.append(number[-1])

    if k > 0:
        answerList = answerList[:-k]

    return "".join(answerList)


print(solution("417725", 3))

# 시간초과를 해결하기 위해서 불필요한 비교를 없애자!
# 수를 answer 리스트에 넣고
# 리스트의 마지막 값과 n을 비교
# n이 더 크면 리스트의 마지막 값 삭제
# 4
# 4 1
# 4 7
# 7
# 7 7
# 7 7 2
# 7 7 5

################ 시간초과 나오는 풀이 ###################

# def solution(number, k):
#     temp = ''
#     while (k > 0):
#         flag = 0
#         for i in range(0, len(number) - 1):
#             if number[i] < number[i + 1]:
#                 temp += number[0:i]
#                 temp += number[i + 1:len(number)]
#                 number = temp
#                 temp = ''
#                 k -= 1
#                 flag = 1
#                 break
#
#         if flag == 0:
#             k -= 1
#             number = number[:-1]
#
#     return number

# 인접한 두 수를 비교해서 앞에꺼가 작으면 제거
# 예를 들어 (417725, 3) 같은 경우에
# 4, 1 비교 후 그대로 두고
# 1, 7 비교 후 1 삭제 -> 47725
# 4, 7 비교 후 4 삭제 -> 7725
# 7 7 비교 후 그대로 두고
# 7 2 비교 후 그대로 두고
# 2 5 비교 후 2 삭제 -> 775
# 근데 삭제가 이루어지면 다시 처음부터 비교를 하기 때문에
# 불필요한 비교횟수가 많아지는 것 때문일까..?