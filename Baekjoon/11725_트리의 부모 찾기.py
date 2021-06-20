N = int(input())
linkNum = int(input())

graph = [[0] * (N + 1) for _ in range(N + 1)]
visited = []

for _ in range(linkNum):
    a, b = input().split()
    a, b = int(a), int(b)
    graph[a][b], graph[b][a] = 1, 1

