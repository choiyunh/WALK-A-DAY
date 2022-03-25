s = []
l = []
for _ in range(5):
    temp = input()
    s.append(temp)
    l.append(len(temp))

for i in range(max(l)):
    for ss in s:
        if i < len(ss):
            print(ss[i], end='')
print('')