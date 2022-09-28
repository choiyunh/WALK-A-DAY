from collections import defaultdict

visited = []
graph = defaultdict(set)
count = 0


def dfs(x):
    global count
    visited[x] = True
    count += 1
    for i in graph[x]:
        if not visited[i]:
            dfs(i)


def solution(n, wires):
    global visited
    global graph
    global count

    answer = []

    for i in range(n - 1):
        visited = [False] * (n + 1)
        graph = defaultdict(set)
        temp = wires.copy()
        temp.pop(i)
        for wire in temp:
            graph[wire[0]].add(wire[1])
            graph[wire[1]].add(wire[0])
        for j in range(1, n + 1):
            count = 0
            if not visited[j]:
                dfs(j)
            if count:
                answer.append(count)
    result = []
    for i in range(0, len(answer), 2):
        result.append(abs(answer[i] - answer[i + 1]))
    return min(result)


print(solution(9, [[1, 3], [2, 3], [3, 4], [4, 5], [4, 6], [4, 7], [7, 8], [7, 9]]))
