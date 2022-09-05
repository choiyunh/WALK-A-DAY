def solution(str1, str2):
    set1 = set()
    dic1 = dict()
    for i in range(len(str1) - 1):
        temp = (str1[i] + str1[i + 1]).upper()
        if temp.isalpha():
            dic1[temp] = dic1.get(temp, 0) + 1
            set1.add(temp)

    set2 = set()
    dic2 = dict()
    for i in range(len(str2) - 1):
        temp = (str2[i] + str2[i + 1]).upper()
        if temp.isalpha():
            dic2[temp] = dic2.get(temp, 0) + 1
            set2.add(temp)

    inter = (set1 & set2)
    union = (set1 | set2)

    first, second = 0, 0
    for a in inter:
        first += min(dic1[a], dic2[a])
    for b in union:
        second += max(dic1.get(b, 0), dic2.get(b, 0))

    try:
        return int((first / second) * 65536)
    except:
        return 65536
