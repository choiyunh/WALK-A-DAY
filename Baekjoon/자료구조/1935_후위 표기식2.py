N = int(input())
s = input()

num = []
for _ in range(N):
    num.append(int(input()))

stack = []
for ss in s:
    if ss.isalpha():
        stack.append(num[ord(ss) - 65])
    else:
        b = stack.pop()
        a = stack.pop()

        if ss == '+':
            stack.append(a + b)
        elif ss == '-':
            stack.append(a - b)
        elif ss == '*':
            stack.append(a * b)
        elif ss == '/':
            stack.append(a / b)

print('%.2f' %stack[-1])