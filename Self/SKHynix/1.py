from collections import defaultdict


def solution(tower, k):
    answer = 0
    dic = defaultdict(list)

    for value, key in tower:
        dic[key].append(value)
    for d in dic.items():
        length = len(d[1])
        for i in range(length - 1):
            if d[1][i + 1] - d[1][i] > k:
                answer += 1
        answer += 1
    return answer
