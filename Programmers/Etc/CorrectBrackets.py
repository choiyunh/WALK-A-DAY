def solution(s):
    answer = 0
    strLen = len(s)

    for x in range(strLen):
        if isCorrect(s[x:] + s[:x]):
            answer += 1
    return answer


def isCorrect(strList):
    stack = []

    for str in strList:
        if str in ('(', '{', '['):
            stack.append(str)
        else:
            if not stack:
                return False
            s = stack.pop()

            if str == ')' and s != '(':
                return False
            elif str == '}' and s != '{':
                return False
            if str == ']' and s != '[':
                return False
    if not stack:
        return True
