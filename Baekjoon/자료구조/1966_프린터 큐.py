from collections import deque

N = int(input())

answer = []
for _ in range(N):
    nDoc, num = map(int, input().split())
    q = deque(input().split())

    while True:
        if q and q[0] == min(q):
            q.popleft()
        else:
            q.append(q.popleft())
