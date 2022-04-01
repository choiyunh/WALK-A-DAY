s = input()

n = len(s)
suffixArray = [i for i in range(n)]
g = [0] * (n + 1)
ng = [0] * (n + 1)

for i in range(n):
    g[i] = ord(s[i])

g[n] = -1
ng[suffixArray[0]] = 0
ng[n] = -1
i = 1

while i < n:
    suffixArray.sort(key=lambda x: (g[x], g[min(x + i, n)]))

    for i in range(1, n):
        p, q = suffixArray[i - 1], suffixArray[i]
        if g[p] != g[q] or g[min(p + i, n)] != g[min(q + i, n)]:
            ng[q] = ng[p] + 1
        else:
            ng[q] = ng[p]

    if ng[n - 1] == n - 1:
        break

    i = i * 2
    g = ng[:]
