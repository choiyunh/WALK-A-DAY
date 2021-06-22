N = int(input())

graph = {}
for _ in range(N - 1):
    a, b = map(int, input().split())
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

answer = [0] * (N + 1)
stack = [1]

print(graph)
print(answer)

p = -1
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
