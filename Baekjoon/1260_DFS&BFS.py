from collections import deque

n, m, v = map(int, input().split())
graph = {}

for _ in range(m):
    a, b = input().split()
    a, b = int(a), int(b)
    if a in list(graph.keys()):
        if b not in graph[a]:
            graph[a].append(b)
    else:
        graph[a] = [b]

    if b in list(graph.keys()):
        if a not in graph[b]:
            graph[b].append(a)
    else:
        graph[b] = [a]


def dfs(v):
    stack = [v]
    visited = []

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            if node in graph:
                temp = sorted(graph[node], reverse=True)
                stack.extend(temp)
    return visited


def bfs(v):
    queue = deque([v])
    visited = []

    while queue:
        node = queue.popleft()
        if node not in visited:
            visited.append(node)
            if node in graph:
                temp = sorted(graph[node])
                queue.extend(temp)
    return visited


print(dfs(v))
print(bfs(v))
