from collections import deque


def solution(bridge_length, weight, truck_weights):
    answer = 0
    queue = deque()

    i = 0
    while i < len(truck_weights):
        if len(queue) == bridge_length:
            queue.popleft()
        if not queue or sum(queue) + truck_weights[i] <= weight:
            queue.append(truck_weights[i])
            i += 1
        else:
            queue.append(0)
        answer += 1
    answer += bridge_length
    return answer


print(solution(2, 10, [7, 4, 5, 6]))
