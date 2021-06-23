n, m = map(int, input().split())
graph = {}
for _ in range(m):
    a, b = map(int, input().split())
    if a in graph:
        graph[a].append(b)
    else:
        graph[a] = [b]

print(graph)

while stack:
    n = stack.pop()
    if not answer[n]:
        answer[n] = p
        if n in graph:
            temp = sorted(graph[n], reverse=True)
            stack.extend(temp)

print(graph)
print(answer)

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