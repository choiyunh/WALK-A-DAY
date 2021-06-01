a, b = input().split()
a, b = max(int(a), int(b)), min(int(a), int(b))

c, d = a, b
while d:
    c, d = d, c % d

print(c)
print(a * b // c)
