def solution(m, musicinfos):
    dic = {}

    for mf in musicinfos:
        info = mf.split(',')

        si = int(info[1][:2]) - int(info[0][:2])
        bun = int(info[1][3:]) - int(info[0][3:])
        time = si * 60 + bun
        songName = info[2]
        sheet = info[3]

        realSheet = []
        for s in sheet:
            if s == '#':
                realSheet[-1] += s
            else:
                realSheet.append(s)

        radio = []
        for i in range(time):
            radio.append(realSheet[i % len(realSheet)])
        # print(radio)
        for i in range(len(radio)):
            if ''.join(radio[i:i + len(m) - m.count('#')]) == m:
                dic[songName] = time

    if not dic:
        return "(None)"
    dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)
    return dic[0][0]


print(solution("CDCDF", ["03:00,03:06,FOO,CDCDCDF", "03:00,03:30,FOOF,CC#B"]))
