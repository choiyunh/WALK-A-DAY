def solution(str1, str2):
    rst1, rst2 = [], []

    for s, part in zip(str1, str1[1:]):
        temp = s + part
        if temp.isalpha():
            rst1.append(temp.lower())

    for s, part in zip(str2, str2[1:]):
        temp = s + part
        if temp.isalpha():
            rst2.append(temp.lower())

    realUnion = set(rst1 + rst2)
    lenInter, lenUnion = 0, 0

    for r in realUnion:
        if r in rst1 and r in rst2:
            lenInter += min(rst1.count(r), rst2.count(r))
        lenUnion += max(rst1.count(r), rst2.count(r))
    if lenUnion == 0:
        return 65536
    answer = int(lenInter / lenUnion * 65536)
    return answer


print(solution('aa1+aa2', 'AAAA12'))

# {1,1,2,2,3} {1,2,2,4,5}
# {1,2,3,4,5}

# {1,2} {1,3}
# {1, 2, 3}
