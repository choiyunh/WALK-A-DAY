def solution(n, a, b):
    answer = 0
    a, b = min(a, b), max(a, b)

    # while not a == b == 1:  # 중간에 만나는 것을 고려 안한 조건
    while a != b:
        answer += 1
        a, b = (a + 1) // 2, (b + 1) // 2
    return answer


print(solution(8, 7, 4))
