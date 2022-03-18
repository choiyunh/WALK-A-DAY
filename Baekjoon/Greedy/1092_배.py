n = int(input())
crane = sorted(list(map(int, input().split())), reverse=True)

m = int(input())
box = sorted(list(map(int, input().split())), reverse=True)

result = 0
count = 0

positions = [0] * n
checked = [0] * m

if box[0] > crane[0]:
    print(-1)
else:
    while count < len(box):
        for i in range(n):
            while positions[i] < len(box):
                if not checked[positions[i]] and crane[i] >= box[positions[i]]:
                    checked[positions[i]] = True
                    positions[i] += 1
                    count += 1
                    break
                positions[i] += 1
        result += 1
    print(result)
