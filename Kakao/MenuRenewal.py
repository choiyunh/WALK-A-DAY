from itertools import combinations


def solution(orders, course):
    answer = []
    comList = [] # 주문한 메뉴에서 나올 수 있는 모든 조합들(course)
    cnt = {} # 위 조합의 출현 횟수

    for c in course:
        for order in orders:
            order = sorted(order) # XYZ
            if len(order) >= c:
                for comb in list(combinations(order, c)):  # [XY XZ YZ]
                    if comb in comList:
                        cnt[comb] += 1
                    else:
                        comList.append(comb)
                        cnt[comb] = 1
        cnt = sorted(cnt.items(), key=lambda x: x[1], reverse=True)

        if cnt:
            temp = cnt[0][1] # [0]:key [1]:value
            for i in cnt:
                if i[1] != temp or temp == 1:
                    break
                tempStr = ''
                for a in i[0]:
                    tempStr += a
                answer.append(tempStr)
        cnt = {}
        comList = []

    answer.sort()
    return answer


print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
