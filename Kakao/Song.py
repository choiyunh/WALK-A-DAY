def solution(m, musicinfos):
    answer = []
    mList = []
    dic = {}
    flag = False
    for i in range(len(m)):
        if flag:
            flag = False
            continue
        if i != len(m) - 1 and m[i + 1] == '#':
            mList.append(m[i] + '#')
            flag = True
        else:
            mList.append(m[i])
    print(mList)
    for mf in musicinfos:
        info = mf.split(',')
        si = int(info[1][:2]) - int(info[0][:2])
        bun = int(info[1][3:]) - int(info[0][3:])
        time = si * 60 + bun
        songName = info[2]
        sheet = info[3]

        lenSheet = len(sheet)
        for s in sheet:
            if s == '#':
                lenSheet -= 1

        realSheet = []
        flag = False
        for i in range(len(sheet) * time // lenSheet):
            if flag:
                flag = False
                continue
            sound = sheet[i % len(sheet)]
            if i % len(sheet) != len(sheet) - 1 and sheet[i % len(sheet) + 1] == '#':
                realSheet.append(sound + '#')
                flag = True
            else:
                realSheet.append(sound)
        print(realSheet)

        j = 0
        while True:
            cnt = 0
            for mm, s in zip(mList, realSheet[j:j + len(mList)]):
                if mm == s:
                    cnt += 1
            if cnt == len(mList):
                dic[songName] = time
                break
            if j >= len(realSheet) - len(mList):
                break
            j += 1
    if not dic:
        return "(None)"
    dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)
    print(dic)
    return dic[0][0]


print(solution("CDCDF", ["03:00,03:07,FOO,CDCDCDF", "03:00,03:30,FOOF,CC#B"]))
