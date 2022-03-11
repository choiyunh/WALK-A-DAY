from collections import deque
import sys

N = int(sys.stdin.readline())

q = deque([i for i in range(1, N + 1)])

while len(q) > 1:
    q.popleft()
    q.append(q.popleft())

print(q[0])
