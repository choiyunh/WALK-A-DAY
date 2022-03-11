N, K = map(int, input().split())

a = [i for i in range(1, N + 1)]

cur = 0
answer = []
while a:
    cur = (cur + (K - 1)) % len(a)
    answer.append(str(a.pop(cur)))
print('<', ', '.join(answer), '>', sep='')
