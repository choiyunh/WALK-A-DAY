n, m = map(int, input().split())
graph = {}
for _ in range(m):
    a, b = map(int, input().split())
    if a in graph:
        graph[a].append(b)
    else:
        graph[a] = [b]


def dfs(v):
    visited.append(v)
    for i in range(1, N + 1):
        if i not in visited and graph[v][i] == 1:
            dfs(i)

print(graph)
