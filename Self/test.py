from itertools import product


def productMatrix(A, B):
    return [[sum(a * b for a, b in zip(A_row, B_col)) for B_col in zip(*B)] for A_row in A]


dic = {'A': [[1, 0], [0, 1]],
       '0': [[1, 0], [1, 1]],
       '1': [[1, 1], [0, 1]]}

data = input().split(';')
X = [list(map(int, d.split())) for d in data]

result = []
ix = 1

while result != X:
    for i in product(['0', '1'], repeat=ix):
        result = dic['A']
        for j in i:
            result = productMatrix(result, dic[j])
        if result == X:
            print(''.join(i))
            break
        ix += 1
