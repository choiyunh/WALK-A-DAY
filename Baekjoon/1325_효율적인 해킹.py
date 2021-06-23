n, m = map(int, input().split())
graph = {}
for _ in range(m):
    a, b = map(int, input().split())
    if a in graph:
        graph[a].append(b)
    else:
        graph[a] = [b]

print(graph)
