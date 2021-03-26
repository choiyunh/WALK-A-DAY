def solution(maps):
    answer = 0
    y, x = 0, 0
    dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # U D L R
    queue = []

    while True:
        # 현 위치에서 이동가능한 곳을 queue에 push
        for dy, dx in dirs:
            moveY, moveX = y + dy, x + dx
            if 0 <= moveY < len(maps) and 0 <= moveX < len(maps[0]) and maps[moveY][moveX]:
                queue.append((moveY, moveX))


    return answer


print(solution([[1, 0, 1, 1, 1], [1, 0, 1, 0, 1], [1, 0, 1, 1, 1], [1, 1, 1, 0, 1], [0, 0, 0, 0, 1]]))
