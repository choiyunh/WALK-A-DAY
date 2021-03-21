def solution(n, words):
    wordList = []
    for item in range(len(words)):
        if not wordList:
            wordList.append(words[item])
        else:
            if words[item] in wordList:
                return [item % n + 1, item // n + 1]
            elif wordList[item-1][-1:] != words[item][:1]:
                return [item % n + 1, item // n + 1]
            else:
                wordList.append(words[item])
    return [0, 0]


solution(3, ["tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"])
