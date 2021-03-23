def solution(s):
    answer = []
    dic = {}

    s = s.replace('{', '').replace('}', '')

    s = s.split(',')

    for ss in s:
        if ss not in dic:
            dic[ss] = 1
        else:
            dic[ss] += 1

    lst = sorted(dic.items(), key=lambda x: x[1], reverse=True)

    for l in lst:
        answer.append(int(l[0]))

    return answer


print(solution("{{4,2,3},{3},{2,3,4,1},{2,3}}"))
