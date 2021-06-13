N = int(input())
linkNum = int(input())

graph = [[0] * (N + 1) for _ in range(N + 1)]
visited = []

for _ in range(linkNum):
    a, b = input().split()
    a, b = int(a), int(b)
    graph[a][b], graph[b][a] = 1, 1


def dfs(v):
    visited.append(v)
    for i in range(1, N + 1):
        if i not in visited and graph[v][i] == 1:
            dfs(i)


dfs(1)
print(len(visited) - 1)
