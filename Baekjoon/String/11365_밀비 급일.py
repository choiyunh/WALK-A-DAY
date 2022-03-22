result = []
while True:
    pw = input()
    if pw == 'END':
        break

    result.append(pw[::-1])
for r in result:
    print(r)
