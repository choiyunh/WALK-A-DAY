from itertools import permutations, product


def solution(word):
    answer = 0
    alpha = ['A', 'E', 'I', 'O', 'U']
    dic = []
    for i in range(1, 6):
        dic.extend(list(map(lambda x: ''.join(x), product(alpha, repeat=i))))
    dic.sort()
    return dic.index(word) + 1


print(solution("AAAAE"))
