from itertools import combinations


def solution(numbers):
    answer = []
    #[(2,1), (2,3), (2,4), (2,1), (1,3) ....]
    for a, b in list(combinations(numbers, 2)):
        if (a + b) not in answer:
            answer.append(a + b)
    answer.sort()

    return answer


print(solution([2, 1, 3, 4, 1]))
