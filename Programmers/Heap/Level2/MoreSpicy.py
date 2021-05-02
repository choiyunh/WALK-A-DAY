import heapq


def solution(scoville, K):
    answer = 0
    hq = []

    for i in scoville:
        heapq.heappush(hq, i)

    while hq[0] < K:
        try:
            heapq.heappush(hq, heapq.heappop(hq) + (heapq.heappop(hq) * 2))
        except IndexError:
            return -1
        answer += 1

    return answer

print(solution([1, 2, 3, 9, 10, 12], 7))
