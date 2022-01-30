import sys

a, b = map(int, sys.stdin.readline().split())
if a == b:
    print(0)
else:
    n = int((b - a) ** 0.5)
    if n ** 2 == b - a:
        print(2 * n - 1)
    else:
        z = (b - a) - n ** 2
        if z <= n:
            print(2 * n)
        else:
            print(2 * n + 1)
