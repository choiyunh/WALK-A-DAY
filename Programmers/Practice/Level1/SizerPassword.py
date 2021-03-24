def solution(s, n):
    answer = ''

    for ss in s:
        if 65 <= ord(ss) <= 90:
            answer += chr((ord(ss) - ord('A') + n) % 26 + ord('A'))
        elif 97 <= ord(ss) <= 122:
            answer += chr((ord(ss) - ord('a') + n) % 26 + ord('a'))
        else:
            answer += ss

    return answer


print(solution('z', 27))
