n = int(input())

seq = []
for _ in range(n):
    seq.append(int(input()))

stack = []

answer = []
num = 1
cnt = 0
for s in seq:
    while not stack or stack[-1] < s:
        stack.append(num)
        num += 1
        answer.append('+')
    while stack and stack[-1] >= s:
        if stack[-1] == s:
            cnt += 1
        stack.pop()
        answer.append('-')

if cnt == n:
    print(*answer, sep='\n')
else:
    print('NO')
