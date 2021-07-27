from collections import deque

N = int(input())

answer = []
for _ in range(N):
    nDoc, num = map(int, input().split())
    printList = input().split()

    q = deque()
    for i in range(len(printList)):
        q.append((i, printList[i]))

    target = q[num]
    cnt = 0
    while True:
        if q[0][1] == max(printList):
            if q[0] == target:
                cnt += 1
                print(cnt)
                break
            else:
                cnt += 1
                printList.remove(q[0][1])
                q.popleft()
        else:
            temp = q.popleft()
            q.append(temp)
