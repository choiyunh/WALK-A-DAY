def solution(people, limit):
    answer = 0
    people.sort()
    i = 0
    j = len(people) - 1
    while i <= j:
        if people[i] + people[j] <= limit:
            i += 1
        j -= 1
        answer += 1

    return answer


print(solution([70, 50, 80, 50]))
