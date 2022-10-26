# 221027 프로그래머스 괄호 회전하기

def isCorrect(s_):
    stack = []

    for c in s_:
        if c in {'(', '{', '['}:
            stack.append(c)
        elif c in {')', '}', ']'}:
            if not stack:
                return False
            temp = stack.pop()
            if c == ')' and temp != '(':
                return False
            elif c == '}' and temp != '{':
                return False
            if c == ']' and temp != '[':
                return False
    if stack:
        return False
    return True


def solution(s):
    answer = 0

    for x in range(len(s)):
        if isCorrect(s[x:] + s[:x]):
            answer += 1

    return answer


print(solution("[](){}"))
