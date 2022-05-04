def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


N, M = map(int, input().split())
print(M - gcd(max(N, M), min(N, M)))
