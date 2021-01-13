def solution(s):
    answer = ''
    wordList = s.split(' ')

    for ix, word in enumerate(wordList):
        for i in range(0, len(word)):
            if(i & 1): # 홀수
                answer += word[i].lower()
            else:
                answer += word[i].upper()
        if not ix == len(wordList)-1:
            answer += ' '
    return answer

print(solution("try hello world"))