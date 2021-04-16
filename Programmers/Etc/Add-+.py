def solution(absolutes, signs):
    answer = 0

    for a, s in zip(absolutes, signs):
        if s:
            answer += a
        else:
            answer -= a
    return answer


print(solution([4, 7, 12], [True, False, True]))
