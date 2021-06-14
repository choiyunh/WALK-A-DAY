n, m, v = input().split()

graph = [[0] * (int(n) + 1) for _ in range(int(n) + 1)]
visited = []

for _ in range(int(m)):
    a, b = input().split()
    graph[int(a)][int(b)] = 1


def dfs(v):
    visited.append(v)
    for i in range(1, int(n) + 1):
        if i not in visited and graph[v][i] == 1:
            dfs(i)


dfs(int(v))
print(visited)
visited = []
