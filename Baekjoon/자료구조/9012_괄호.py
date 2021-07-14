from collections import deque

T = int(input())

arr = []

for _ in range(T):
    arr.append(input())

for s in arr:
    q = deque()
    flag = False
    for ss in s:
        if ss == '(':
            q.append(ss)
        else:
            if q:
                q.popleft()
            else:
                flag = True
                break
    if q or flag:
        print('NO')
    else:
        print('YES')
