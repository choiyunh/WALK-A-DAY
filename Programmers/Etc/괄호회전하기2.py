# 221030 괄호 회전하기

def solution(s):
    def isCorrect(ss):
        stack = []
        for c in ss:
            if c in ['(', '{', '[']:
                stack.append(c)
            else:
                if not stack:
                    return False
                p = stack.pop()

                if c == ')' and p != '(':
                    return False
                elif c == '}' and p != '{':
                    return False
                if c == ']' and p != '[':
                    return False
        if stack:
            return False
        return True

    answer = 0
    for x in range(len(s)):
        if isCorrect(s[x:] + s[:x]):
            answer += 1

    return answer