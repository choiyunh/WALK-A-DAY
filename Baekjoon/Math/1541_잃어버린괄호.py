s = input()
num = []
temp = ""
minus = 1

for c in s:
    if c == '+' or c == '-':
        num.append(minus * int(temp))
        temp = ""
        if c == '-':
            minus = -1
    else:
        temp += c
num.append(minus * int(temp))

print(sum(num))
