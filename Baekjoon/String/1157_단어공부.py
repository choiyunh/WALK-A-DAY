s = input().upper()
dic = {}

for c in s:
    dic[c] = dic.get(c, 0) + 1

result = sorted(dic.items(), key=lambda x: x[1])
if len(result) > 1 and result[-1][1] == result[-2][1]:
    print('?')
else:
    print(result[-1][0])
