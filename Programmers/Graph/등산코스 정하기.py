from collections import defaultdict
from heapq import heappop, heappush


def solution(n, paths, gates, summits):
    def dijkstra():
        pq = []
        intensity = [int(1e9)] * (n + 1)

        for gate in gates:
            heappush(pq, (0, gate))
            intensity[gate] = 0
        while pq:
            intensit, node = heappop(pq)

            if node in summitsSet or intensit > intensity[node]:
                continue
            for weight, nextNode in graph[node]:
                newIntensity = max(intensit, weight)
                if newIntensity < intensity[nextNode]:
                    intensity[nextNode] = newIntensity
                    heappush(pq, (newIntensity, nextNode))

        minIntensity = [0, int(1e9)]
        for summit in summits:
            if intensity[summit] < minIntensity[1]:
                minIntensity[0] = summit
                minIntensity[1] = intensity[summit]

        return minIntensity

    graph = defaultdict(list)
    for i, j, w in paths:
        graph[i].append((w, j))
        graph[j].append((w, i))
    summits.sort()
    summitsSet = set(summits)

    return dijkstra()


print(
    solution(6,
             [[1, 2, 3], [2, 3, 5], [2, 4, 2], [2, 5, 4], [3, 4, 4], [4, 5, 3], [4, 6, 1], [5, 6, 1]],
             [1, 3],
             [5]))
