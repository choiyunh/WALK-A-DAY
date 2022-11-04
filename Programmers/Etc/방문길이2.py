def solution(dirs):
    save = set()
    dic = {'U': (-1, 0), 'D': (1, 0), 'R': (0, 1), 'L': (0, -1)}
    x, y = 0, 0
    for d in dirs:
        nx, ny = x + dic[d][0], y + dic[d][1]
        if -5 <= nx <= 5 and -5 <= ny <= 5:
            save.add((x, y, nx, ny))
            save.add((nx, ny, x, y))
            x, y = nx, ny
    return len(save) // 2