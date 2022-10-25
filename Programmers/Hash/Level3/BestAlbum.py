from collections import defaultdict

def solution(genres, plays):
    answer = []

    songDic = defaultdict(list)
    playNumDic = defaultdict(int)

    for i in range(len(plays)):
        songDic[genres[i]].append((i, plays[i]))
        playNumDic[genres[i]] += plays[i]

    playNumDic = dict(sorted(playNumDic.items(), key=lambda x: x[1], reverse=True))

    for sd in songDic:
        songDic[sd].sort(key=lambda x: (-x[1], x[0]))

    for pnd in playNumDic.keys():
        for sd in songDic[pnd][:2]:
            answer.append(sd[0])

    return answer