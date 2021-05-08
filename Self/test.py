def solution(n):
    dic = {0: '짝', 1: '홀'}

    print(dic[int(format(n, 'b')[-1])])


def solution2(n):
    dic = {0: 'F', 1: 'F', 2: 'F', 3: 'F', 4: 'F', 5: 'F', 6: 'D', 7: 'C', 8: 'B', 9: 'A'}

    print(dic[n // 10])


solution(10)
solution2(70)
