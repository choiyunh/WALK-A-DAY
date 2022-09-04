def isCorrect(s):
    stack = []
    for c in s:
        if c == '(':
            stack.append('(')
        else:
            if len(stack) == 0:
                return False
            stack.pop()
    return len(stack) == 0


def isBalanced(s):
    return s.count('(') == s.count(')')


def convert(s):
    if len(s) == 0:
        return s

    for i in range(2, len(s) + 1):
        if isBalanced(s[:i]):
            u = s[:i]
            v = s[i:]
            break

    if isCorrect(u):
        return u + convert(v)
    else:
        result = '(' + convert(v) + ')'

        for i in range(1, len(u) - 1):
            if u[i] == '(':
                result += ')'
            else:
                result += '('
    return result


def solution(p):
    answer = convert(p)

    return answer
