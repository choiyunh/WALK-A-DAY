N = int(input())
wordList = []

for i in range(N):
    wordList.append(input())

##################################
# stack[-1]과 다른데 stack에 존재하면 연속X
# [a,a,b] a
cnt = 0
for word in wordList:
    flag = 1
    stack = []
    for c in word:
        if stack and stack[-1] != c and c in stack:
            flag = 0
            break
        else:
            stack.append(c)
    if flag == 1:
        cnt += 1

print(cnt)
