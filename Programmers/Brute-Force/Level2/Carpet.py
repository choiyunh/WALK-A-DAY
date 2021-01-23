def solution(brown, yellow):
    sum = brown + yellow

    for i in range(3, sum):
        if sum % i == 0:
            w = i
            h = (int)(sum / i)
            if (w - 2) * (h - 2) == yellow:
                break

    return sorted([w, h], reverse=True)


print(solution(10, 2))
