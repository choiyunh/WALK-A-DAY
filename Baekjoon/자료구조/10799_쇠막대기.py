s = input()

answer = 0
stick = 0
for i in range(len(s)):
    if s[i] == '(':
        if s[i + 1] == ')':
            answer += stick
        else:
            answer += 1
            stick += 1
    else:
        if s[i - 1] == '(':
            continue
        stick -= 1

print(answer)
