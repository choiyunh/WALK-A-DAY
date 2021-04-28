def solution(progresses, speeds):
    answer = []
    days = []

    for p, s in zip(progresses, speeds):
        day = -((p - 100) // s)
        if not len(days) or day > days[-1]:
            days.append(day)
            answer.append(1)
        else:
            answer[-1] += 1
    return answer


print(solution([2, 2, 1, 2], [1, 1, 1, 1]))
