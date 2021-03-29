def solution(dartResult):
    score = dartResult.replace('S', ' ').replace('D', ' ').replace('T', ' ').replace('*', ' ').replace('#', ' ').split()

    i = 0
    for r in dartResult:
        if r == 'S':
            score[i] = int(score[i])
            i += 1
        elif r == 'D':
            score[i] = int(score[i]) ** 2
            i += 1
        elif r == 'T':
            score[i] = int(score[i]) ** 3
            i += 1
        elif r == '*':
            if i < 2:
                score[i - 1] = int(score[i - 1]) * 2
            else:
                score[i - 1] = int(score[i - 1]) * 2
                score[i - 2] = int(score[i - 2]) * 2
        elif r == '#':
            score[i - 1] = int(score[i - 1]) * -1
    answer = sum(score)
    return answer


print(solution("1D2S#10S"))
