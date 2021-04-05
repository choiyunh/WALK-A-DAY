from itertools import combinations


def solution(relation):
    answer = 0
    row = len(relation)
    col = len(relation[0])

    candiKey = []

    attribute = [a for a in range(col)]

    for n in range(1, col + 1):
        combiList = []
        combiList += list(combinations(attribute, n))
        for i in range(len(combiList)):
            combiList[i] = set(combiList[i])

        for ck in candiKey:
            for ix in range(len(combiList)):
                if len(ck & combiList[ix]) == len(ck):
                    combiList[ix] = set()

        for cl in combiList:
            temp = set()
            for r in range(row):
                key = []
                for cc in cl:
                    key.append(relation[r][cc])
                temp.add(tuple(key))
            if len(temp) == row:
                candiKey.append(cl)
                answer += 1
    return answer


print(solution([["100", "ryan", "music", "2"], ["200", "apeach", "math", "2"], ["300", "tube", "computer", "3"],
                ["400", "con", "computer", "1"], ["500", "muzi", "music", "3"], ["600", "apeach", "music", "2"]]))
