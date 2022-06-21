def hanoi(n_, a, b):
    if n_ > 1:
        hanoi(n_ - 1, a, 6 - a - b)
    print(a, b)

    if n_ > 1:
        hanoi(n_ - 1, 6 - a - b, b)


n = int(input())

print(2**n - 1)
hanoi(n, 1, 3)
