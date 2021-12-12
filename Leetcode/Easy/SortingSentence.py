class Solution:
    def sortSentence(self, s: str) -> str:
        wordDic = {}
        result = ""

        for word in s.split():
            wordDic[word[-1]] = word[:-1]

        for item in sorted(wordDic.items()):
            result += item[1] + " "

        return result[:-1]
