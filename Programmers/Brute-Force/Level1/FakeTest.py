def solution(answers):
    answer = []

    one = [1, 2, 3, 4, 5]
    two = [2, 1, 2, 3, 2, 4, 2, 5]
    three = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    score = [0, 0, 0]

    i = 0
    for a in answers:
        if a == one[i % len(one)]:
            score[0] += 1
        if a == two[i % len(two)]:
            score[1] += 1
        if a == three[i % len(three)]:
            score[2] += 1
        i += 1

    for i in range(len(score)):
        if score[i] == max(score):
            answer.append(i + 1)
    return answer


print(solution([1, 2, 3, 4, 5]))
