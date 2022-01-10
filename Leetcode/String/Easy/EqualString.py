class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        firstWord = ""
        secondWord = ""

        for w1 in word1:
            firstWord += w1
        for w2 in word2:
            secondWord += w2

        return firstWord == secondWord
