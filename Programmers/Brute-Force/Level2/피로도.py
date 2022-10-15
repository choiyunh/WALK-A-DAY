# 2022/10/15 피로도

from itertools import permutations


def solution(k, dungeons):
    answer = []
    index = [i for i in range(len(dungeons))]
    for pmt in list(permutations(index, len(dungeons))):
        tempK = k
        count = 0
        for p in pmt:
            if tempK >= dungeons[p][0]:
                tempK -= dungeons[p][1]
                count += 1
        answer.append(count)
    return max(answer)


solution(80, [[80, 20], [50, 40], [30, 10]])
