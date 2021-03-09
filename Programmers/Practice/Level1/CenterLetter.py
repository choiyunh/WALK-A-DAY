def solution(s):
    answer = ''
    sLen = len(s)

    if sLen & 1:
        answer = s[sLen // 2]
    else:
        answer = s[(sLen // 2) - 1:(sLen // 2) + 1]
    return answer


print(solution('abdcd'))
