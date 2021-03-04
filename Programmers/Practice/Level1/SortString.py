def solution(strings, n):
    answer = []

    for string in strings:
        answer.append(string[n] + string)
    answer.sort()

    for i in range(len(answer)):
        answer[i] = answer[i][1:]
    return answer


print(solution(["sun", "bed", "car"], 1))
