def solution(dirs):
    answer = 0
    x, y = 0, 0
    moveDir = {'U': 1, 'D': -1, 'L': -1, 'R': 1}
    visit = []

    for dir in dirs:
        moveX, moveY = x, y
        temp, temp2 = [], []

        if dir in ['U', 'D']:
            moveY += moveDir[dir]
        elif dir in ['L', 'R']:
            moveX += moveDir[dir]

        if not (-5 <= moveX <= 5) or not (-5 <= moveY <= 5):
            continue

        temp += x, y, moveX, moveY
        temp2 += moveX, moveY, x, y
        if temp not in visit:
            visit.append(temp)
            visit.append(temp2)
            answer += 1
        x, y = moveX, moveY

    return answer