import sys

input = sys.stdin.readline

R, C = map(int, input().split())
arr = []
checkpoint = [[] for _ in range(C)]
for _ in range(R):
    arr.append(list(input().rstrip()))
N = int(input())


def falling(x, y, line):
    while True:
        checkpoint[line].append([x, y])
        if x + 1 == R or arr[x + 1][y] == "X":
            arr[x][y] = "O"
            return
        if arr[x + 1][y] == "O":
            if y - 1 >= 0 and arr[x][y - 1] == "." and arr[x + 1][y - 1] == ".":
                y -= 1
            elif y + 1 < C and arr[x][y + 1] == "." and arr[x + 1][y + 1] == ".":
                y += 1
            else:
                arr[x][y] = "O"
                return
        x += 1


for _ in range(N):
    _input = int(input()) - 1

    while checkpoint[_input]:
        cx, cy = checkpoint[_input][-1]
        if arr[cx][cy] == '.':
            break
        checkpoint[_input].pop()

    if checkpoint[_input]:
        cx, cy = checkpoint[_input].pop()
        falling(cx, cy, _input)
    else:
        falling(0, _input, _input)

    cx, cy = checkpoint[_input].pop()
    arr[cx][cy] = "O"

for a in arr:
    print("".join(a))