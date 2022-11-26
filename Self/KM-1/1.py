# 221126

from collections import defaultdict

def solution(flowers):
    days = defaultdict(int)
    for flower in flowers:
        for idx in range(flower[0], flower[1]):
            days[idx] += 1
    return len(days)