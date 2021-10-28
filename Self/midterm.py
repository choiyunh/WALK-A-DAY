dataList = []  # 리스트
dataDic = {}  # 딕셔너리(key = 이름)
firstLine = []


def readFileToList():
    with open("point.txt", 'r', encoding='utf-16') as f:
        lines = f.readlines()

    firstLine.append(lines[0].replace('\n', ''))

    for line in lines[1:]:
        line = line.replace('\n', '').split('\t')
        dataList.append(line)

    print(dataList)


def readFileToDic():
    with open("point.txt", 'r', encoding='utf-16') as f:
        lines = f.readlines()

    for line in lines[1:]:
        line = line.replace('\n', '').split('\t')
        dataDic[line[0]] = line[1:]

    print(dataDic)


def getAvg():
    for key in dataDic:
        score = [float(i) for i in dataDic[key]]
        dataDic[key].append(str(sum(score) / len(score)))


def updateAvg():
    temp = firstLine[0] + "\t평균"
    firstLine[0] = temp
    for key in dataDic:
        temp += key + "\t"
        temp += "\t".join(dataDic[key]) + '\n'
    with open("point.txt", 'w', encoding='utf-16') as f:
        f.write(temp)


def getRank():
    avgs = []
    for key in dataDic:
        avgs.append(float(dataDic[key][-1]))
    sortedAvgs = sorted(avgs, reverse=True)
    ranks = [sortedAvgs.index(v) + 1 for v in avgs]

    i = 0
    for key in dataDic:
        dataDic[key].append(str(ranks[i]))
        i += 1


def updateRank():
    temp = firstLine[0] + "\t등수"
    firstLine[0] = temp

    for key in dataDic:
        temp += key + "\t"
        temp += "\t".join(dataDic[key]) + '\n'
    with open("point.txt", 'w', encoding='utf-16') as f:
        f.write(temp)


def getGrade():
    for key in dataDic:
        percent = (float(dataDic[key][-1]) / len(dataDic)) * 100

        if 0 < percent <= 20:
            dataDic[key].append('A')
        elif 20 < percent <= 40:
            dataDic[key].append('B')
        elif 40 < percent <= 60:
            dataDic[key].append('C')
        elif 60 < percent <= 80:
            dataDic[key].append('D')
        elif 80 < percent <= 100:
            dataDic[key].append('F')


def updateGrade():
    temp = firstLine[0] + "\t학점\n"
    firstLine[0] = temp

    for key in dataDic:
        temp += key + "\t"
        temp += "\t".join(dataDic[key]) + '\n'
    with open("point.txt", 'w', encoding='utf-16') as f:
        f.write(temp)


readFileToList()
readFileToDic()
getAvg()
updateAvg()
getRank()
updateRank()
getGrade()
updateGrade()
