from collections import deque

n, m = map(int, input().split())
q = deque(range(1, n+1))
loc = deque(map(int, input().split()))

result = 0
while loc:
    mid = len(q)//2
    if q.index(loc[0]) > mid:
        while loc[0] != q[0]:
            q.appendleft(q.pop())
            result += 1
        q.popleft()
        loc.popleft()
    else:
        while loc[0] != q[0]:
            q.append(q.popleft())
            result += 1
        q.popleft()
        loc.popleft()
print(result)
