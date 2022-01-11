class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        answer = 0
        for sentence in sentences:
            sentenceLength = len(sentence.split())
            if sentenceLength > answer:
                answer = sentenceLength

        return answer
