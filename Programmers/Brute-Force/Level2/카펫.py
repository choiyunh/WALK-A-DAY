def solution(brown, yellow):
    answer = []
    total = brown + yellow

    for i in range(1, int(total ** 0.5) + 1):
        if total % i == 0:
            width = total // i
            height = i
            if ((height - 2) * width) - (2 * (height - 2)) >= yellow:
                answer = [width, height]
                break
    return answer

print(solution(10, 2))
print(solution(8, 1))
print(solution(24, 24))