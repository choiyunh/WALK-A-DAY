from collections import deque

N = int(input())

answer = []
for _ in range(N):
    nDoc, num = map(int, input().split())
    q = deque(input().split())

    target = q[num]
    cnt = 0
    while True:
        if q[0] == max(q):
            if q[0] == target:
                cnt += 1
                print(cnt)
                break
            else:
                cnt += 1
                q.popleft()
        else:
            temp = q.popleft()
            q.append(temp)
