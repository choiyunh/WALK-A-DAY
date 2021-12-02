def solution(msg):
    answer = []
    dic = {}

    for i in range(1, 27):
        dic[chr(64 + i)] = i

    i = 0
    msg += '-'
    while i < len(msg) - 1:
        j = 2
        w = msg[i:i + j]
        while w in dic:
            j += 1
            w = msg[i:i + j]

        answer.append(dic[w[:-1]])
        dic[w] = len(dic) + 1
        i += (len(w) - 1)

    return answer


print(solution("TOBEORNOTTOBEORTOBEORNOT"))
