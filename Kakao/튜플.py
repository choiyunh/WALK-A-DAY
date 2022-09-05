def solution(s):
    s = s.replace('{', '').replace('}', '').split(',')

    dic = dict()
    for c in s:
        dic[c] = dic.get(c, 0) + 1

    answer = list(map(lambda x: int(x[0]),
                      sorted(dic.items(), key=lambda x: x[1], reverse=True)))

    return answer
