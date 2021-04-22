def solution(s):
    if not s.isdigit():
        return False
    else:
        if len(s) in (4,6):
            return True
        else:
            return False

print('1234'.isdigit())
print(solution('1234'))
