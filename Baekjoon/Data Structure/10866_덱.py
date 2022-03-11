from collections import deque
import sys

N = int(sys.stdin.readline())

dq = deque()
for _ in range(N):
    com = sys.stdin.readline().split()

    if com[0] == 'push_front':
        dq.appendleft(com[1])
    elif com[0] == 'push_back':
        dq.append(com[1])
    elif com[0] == 'pop_front':
        if dq:
            print(dq.popleft())
        else:
            print(-1)
    elif com[0] == 'pop_back':
        if dq:
            print(dq.pop())
        else:
            print(-1)
    elif com[0] == 'size':
        print(len(dq))
    elif com[0] == 'empty':
        if dq:
            print(0)
        else:
            print(1)
    elif com[0] == 'front':
        if dq:
            print(dq[0])
        else:
            print(-1)
    elif com[0] == 'back':
        if dq:
            print(dq[-1])
        else:
            print(-1)
