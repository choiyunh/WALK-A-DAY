# 2022/10/09 할인 행사

from collections import defaultdict


def solution(want, number, discount):
    answer = 0
    lenD = len(discount)
    lenW = len(want)
    dic = defaultdict(int)
    for i in range(lenD):
        if i < 10:
            dic[discount[i]] += 1
        else:
            dic[discount[i - 10]] -= 1
            dic[discount[i]] += 1
        cnt = 0
        for k in range(lenW):
            if dic[want[k]] >= number[k]:
                cnt += 1
        if cnt == lenW:
            answer += 1
    return answer
