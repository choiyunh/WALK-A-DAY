def solution(N, stages):
    dic = {}

    for i in range(1, N + 1):
        dic[i] = 0
        son, mom = 0, 0
        for s in stages:
            if s >= i:
                mom += 1
                if s == i:
                    son += 1
        if not mom:
            dic[i] = son
        else:
            dic[i] = son / mom
    dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)

    answer = []
    for d in dic:
        answer.append(d[0])

    return answer


print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
