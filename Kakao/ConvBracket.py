def CheckBalance(str):
    cnt = 0
    for s in str:
        if s == '(':
            cnt += 1
        elif s == ')':
            cnt -= 1

    if not cnt:
        return True
    else:
        return False


def CheckRight(str):
    stack = []
    for s in str:
        if s == '(':
            stack.append('(')
        elif s == ')':
            if not stack:
                return False
            stack.pop()

    if not stack:
        return True
    else:
        return False


def solution(p):
    if not p or CheckRight(p):
        return p

    for i in range(len(p)):
        if CheckBalance(p[:i + 1]):
            u, v = p[:i + 1], p[i + 1:]
            break
    print(u, v)
    if CheckRight(u):
        return u + solution(v)
    else:
        newStr = '(' + solution(v) + ')'
        u = u[1:-1]
        for uu in u:
            if uu == '(':
                newStr += ')'
            elif uu == ')':
                newStr += '('
        print(newStr)
    return newStr


print(solution("()))((()"))
