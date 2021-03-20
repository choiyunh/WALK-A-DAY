def solution(s):
    answer = sorted(s, reverse=True)

    return ''.join(answer)


print(solution('Zbc'))
