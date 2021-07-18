import sys

n = int(input())

seq = []
for _ in range(n):
    seq.append(int(input()))

stack = []

num = 1
for s in seq:
    while not stack or stack[-1] < s:
        stack.append(num)
        num += 1
        print('+')
    while stack and stack[-1] >= s:
        stack.pop()
        print('-')
