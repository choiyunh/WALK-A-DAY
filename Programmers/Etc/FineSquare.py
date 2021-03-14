def solution(w, h):
    answer = 0

    if w == h:
        return w * h - w
    if h == 1:
        return 0

    for x in range(1, w):
        answer += (h * w - h * x) // w

    return answer * 2


print(solution(8, 12))
