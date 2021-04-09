def solution(prices):
    answer = []
    stack = [prices[0]]
    i = 1
    while stack:
        answer.append(0)
        for j in range(i, len(prices)):
            answer[i - 1] = j - i + 1
            if prices[j] < stack[-1]:
                break
        stack.pop()
        if i < len(prices):
            stack.append(prices[i])
        i += 1

    return answer


print(solution([1, 2, 3, 2, 3]))
