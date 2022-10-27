# 221028 영어 끝말잇기

def solution(n, words):
    wordSet = set()
    wordSet.add(words[0])
    for i in range(1, len(words)):
        if words[i][0] != words[i - 1][-1] or words[i] in wordSet:
            return [i % n + 1, i // n + 1]
        else:
            wordSet.add(words[i])
    return [0, 0]