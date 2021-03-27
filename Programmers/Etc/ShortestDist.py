from collections import deque


def solution(maps):
    answer = [[-1 for i in range(len(maps[0]))] for j in range(len(maps))]
    answer[0][0] = 1
    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # U D L R
    queue = deque()
    queue.append((0, 0))

    while queue:
        y, x = queue.popleft()

        # 현 위치에서 이동가능한 곳을 queue에 push
        for dy, dx in dirs:
            moveY, moveX = y + dy, x + dx
            if 0 <= moveY < len(maps) and 0 <= moveX < len(maps[0]) and maps[moveY][moveX]:
                if answer[moveY][moveX] == -1:
                    answer[moveY][moveX] = answer[y][x] + 1
                    queue.append((moveY, moveX))
                elif answer[moveY][moveX] > answer[y][x] + 1:
                    answer[moveY][moveX] = answer[y][x] + 1
                    queue.append((moveY, moveX))

    return answer[-1][-1]


print(solution([[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]))
