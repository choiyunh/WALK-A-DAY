def solution(info, query):
    answer = []

    dic = []
    temp = []
    for i in info:
        for t in i.split():
            temp.append(t)
        dic.append(temp)
        temp = []
    print(dic)

    for q in query:
        for qq in q.split():
            if qq in ['and', '-']:
                continue
            i = 0
            for d in dic:
                if qq == d[i]:
                    answer.append(d)
    print(answer)
    return answer


solution(["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150",
          "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"],
         ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200",
          "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100",
          "- and - and - and - 150"])
