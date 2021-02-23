def solution(s):
    answer = 0
    stack = []

    for a in s:
        if stack and (stack[-1] == a):
            stack.pop()
        else:
            stack.append(a)

    if not stack:
        answer = 1

    return answer


print(solution('cdcd'))
