while(1):
    N = input()
    result = 1

    if N == '0':
        break

    for n in N:
        if n == '0':
            result += 5
        elif n == '1':
            result += 3
        else:
            result += 4
    print(result)
