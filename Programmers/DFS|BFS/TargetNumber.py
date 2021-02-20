def solution(numbers, target):
    answer = 0

    stack = [[0, -numbers[0]], [0, numbers[0]]]

    while stack:
        i, value = stack.pop()
        i += 1
        if i < len(numbers):
            stack.append([i, value - numbers[i]])
            stack.append([i, value + numbers[i]])
        else:
            if value == target:
                answer += 1
    return answer


print(solution([1, 1, 1, 1, 1], 3))
