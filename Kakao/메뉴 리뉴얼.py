from itertools import combinations


def solution(orders, course):
    answer = []

    for i in range(len(orders)):
        orders[i] = "".join(sorted(orders[i]))

    for c in course:
        combiList = []
        for order in orders:
            combiList.extend(list(combinations(order, c)))

        dic = {}
        for i in range(len(combiList)):
            dic[combiList[i]] = dic.get(combiList[i], 0) + 1

        candidates = [k for k, v in dic.items() if max(dic.values()) == v != 1]
        for c in candidates:
            answer.append("".join(c))

    return sorted(answer)
