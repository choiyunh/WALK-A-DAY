from collections import deque


def solution(priorities, location):
    answer = 0
    queue = deque()

    for i in range(len(priorities)):
        queue.append((i, priorities[i]))

    while True:
        if queue[0][1] < max(priorities):
            temp = queue.popleft()
            queue.append(temp)
        else:
            answer += 1
            if queue[0][0] == location:
                break
            queue.popleft()
            priorities.pop(priorities.index(max(priorities)))
    return answer


print(solution([1, 1, 9, 1, 1, 1], 0))
