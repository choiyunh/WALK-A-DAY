def solution(info, query):
    answer = []
    dic = {}

    for infoStr in info:
        temp = infoStr.split()

        keyStr = ""
        for t in temp[:4]:
            keyStr += t

        if keyStr in dic:  # 조건이 같은 사람이 여러 명 있을 수도 있네?
            dic[keyStr].append(temp[4])
        else:
            dic[keyStr] = [temp[4]]
        # print(keyStr, dic[keyStr])
    # print('')

    for queryStr in query:
        # print('queryStr: ' + queryStr)
        flag = 1
        cnt = 0
        tempArr = []
        for s in queryStr.split():
            cnt += 1
            if s == 'and':
                continue
            elif cnt < 8:
                # print('s: ' + s)
                if flag == 1:  # 첫 조건은 모든 키 중에서 포함여부 확인
                    flag += 1
                    if s == '-':
                        for key in dic.keys():
                            tempArr.append(key)
                    else:
                        for key in dic.keys():
                            if s in key:
                                tempArr.append(key)
                else:  # 두 번째 조건 부터는 첫 조건을 통과한 키 중에서 확인
                    if s == '-':
                        continue
                    else:
                        for key in tempArr[:]:
                            if s not in key:
                                tempArr.remove(key)
                # print(tempArr)
            else:  # tempArr에 저장된 key값들의 점수를 query 점수와 비교
                tempRes = 0
                for key in tempArr:
                    for score in dic[key]:
                        # print(score, s)
                        if int(s) <= int(score):
                            tempRes += 1
                    # print(tempRes)
                answer.append(tempRes)

    return answer


info = ["java backend junior pizza 150",
        "python frontend senior chicken 210",
        "python frontend senior chicken 150",
        "cpp backend senior pizza 260",
        "java backend junior chicken 80",
        "python backend senior chicken 50"]

query = ["java and backend and junior and pizza 100",
         "python and frontend and senior and chicken 200",
         "cpp and - and senior and pizza 250",
         "- and backend and senior and - 150",
         "- and - and - and chicken 100",
         "- and - and - and - 150",
         "- and - and - and - 500"]

print(solution(info, query))
