# 221119 압축

def solution(msg):
    dic = dict()
    for i in range(1, 27):
        dic[chr(64 + i)] = i

    answer = []
    i = 0
    while i < len(msg):
        j = 2
        w = msg[i:i + j]
        while w in dic:
            if i + j >= len(msg):
                return answer + [dic[w]]
            j += 1
            w = msg[i:i + j]
        answer.append(dic[w[:-1]])
        dic[w] = len(dic) + 1
        i += (len(w) - 1)
    return answer
