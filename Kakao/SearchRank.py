from itertools import combinations


def solution(orders, course):
    answer = []

    for c in course:
        for order in orders:
            order = sorted(order) # XYZ
            if len(order) >= c:
                for comb in list(combinations(order, c)):  # [XY XZ YZ]
                    if comb in comList:
                        cnt[comb] += 1


    answer.sort()
    return answer


print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
