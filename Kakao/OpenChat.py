def solution(record):
    answer = []
    dic = {}
    stringList = []
    idList = []

    for r in record:
        stringList = r.split()

        if stringList[0] == 'Enter':
            dic[stringList[1]] = stringList[2]
            answer.append('님이 들어왔습니다.')
            idList.append(stringList[1])
        elif stringList[0] == 'Leave':
            answer.append('님이 나갔습니다.')
            idList.append(stringList[1])
        elif stringList[0] == 'Change':
            dic[stringList[1]] = stringList[2]

    for i in range(len(answer)):
        answer[i] = dic[idList[i]] + answer[i]

    return answer


solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"])
