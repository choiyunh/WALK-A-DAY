def solution(s):
    answer = ''

    for word in s.split(' '):
        word = word.lower()
        word = word[:1].upper() + word[1:]
        answer += word + ' '

    return answer[:-1]


print(solution("3people         unFollowed me"))
