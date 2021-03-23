def solution(s):
    answer = True
    stk = []

    for b in s:
        if b == '(':
            stk.append(b)
        elif b == ')':
            if not stk:
                answer = False
                break
            elif stk[-1] == '(':
                stk.pop()

    if stk:
        answer = False

    return answer


print(solution(')()('))