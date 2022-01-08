class Solution:
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            half = int(len(word) / 2)

            if len(word) & 1:
                if word[:half] == word[:half:-1]:
                    return word
            else:
                if word[:half] == word[:half - 1:-1]:
                    return word
        return ""
