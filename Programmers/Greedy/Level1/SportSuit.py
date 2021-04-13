def solution(n, lost, reserve):
    answer = [1 for i in range(n)]

    for r in reserve:
        answer[r - 1] += 1
    for l in lost:
        answer[l - 1] -= 1

    for i in range(len(answer)):
        if not answer[i]:
            if i != 0 and answer[i - 1] == 2:
                answer[i] += 1
                answer[i - 1] -= 1
            elif i != len(answer) - 1 and answer[i + 1] == 2:
                answer[i] += 1
                answer[i + 1] -= 1

    return len(answer) - answer.count(0)


print(solution(5, [1, 5], [1, 3]))
