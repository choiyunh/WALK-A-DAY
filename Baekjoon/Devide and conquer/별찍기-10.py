def printStar(n):
    if n == 1:
        return ['*']

    stars = printStar(n // 3)
    line = []

    for star in stars:
        line.append(star * 3)
    for star in stars:
        line.append(star + ' ' * (n // 3) + star)
    for star in stars:
        line.append(star * 3)

    return line


N = int(input())
print('\n'.join(printStar(N)))
