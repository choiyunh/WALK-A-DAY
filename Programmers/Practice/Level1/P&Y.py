def solution(s):
    s = s.lower()
    if s.count('p') - s.count('y'):
        return False
    else:
        return True


print(solution("pPoooyY"))
