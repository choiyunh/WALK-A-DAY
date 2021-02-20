def solution(new_id):
    answer = ''

    # 1
    new_id = new_id.lower()

    # 2
    for c in new_id:
        if c.isalnum():
            answer += c
        elif c == '-' or c == '_' or c == '.':
            answer += c

    # 3
    while '..' in answer:
        answer = answer.replace('..', '.')

    # 4
    if len(answer) > 0 and answer[0] == '.':
        answer = answer[1:]
    # if len(answer) > 0 and answer[-1] == '.':
    #     answer = answer[:-1]

    # 5
    if answer == '':
        answer = 'a'

    # 6
    if len(answer) >= 16:
        answer = answer[:15]
    if len(answer) > 0 and answer[-1] == '.':
        answer = answer[:-1]

    # 7
    if len(answer) <= 2:
        while len(answer) < 3:
            answer += answer[-1]

    return answer


print(solution("=.="))
