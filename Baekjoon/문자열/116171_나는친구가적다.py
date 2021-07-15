S = input()
K = input()

newStr = ''
for s in S:
    if s.isalpha():
        newStr += s

print(int(K in newStr))
