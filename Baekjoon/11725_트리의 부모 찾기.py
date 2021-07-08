N = int(input())

graph = {}
for _ in range(N - 1):
    a, b = map(int, input().split())
    if a in graph:
        if b not in graph[a]:
            graph[a].append(b)
    else:
        graph[a] = [b]

    if b in graph:
        if a not in graph[b]:
            graph[b].append(a)
    else:
        graph[b] = [a]

answer = [0] * (N + 1)
stack = [1]

while stack:
    n = stack.pop()
    if answer[n]:
        continue
    if n in graph:
        if n == 1:
            answer[n] = -1
        else:
            for v in graph[n]:
                if answer[v]:
                    answer[n] = v
        temp = sorted(graph[n], reverse=True)
        stack.extend(temp)

print(*answer[2:], sep='\n')
