def solution(seoul):
    cnt = 0

    for s in seoul:
        if s == 'Kim':
            break
        cnt += 1
    answer = '김서방은 ' + str(cnt) + '에 있다.'
    return answer


print(solution(['a','Kim']))