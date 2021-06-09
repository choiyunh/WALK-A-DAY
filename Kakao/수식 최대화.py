from itertools import permutations


def solution(expression):
    # 우선순위의 순열
    oper = list(permutations(['+', '-', '*'], 3))

    prev = 0
    newExp = []

    # 수식 파싱해서 리스트로 변환
    for i in range(len(expression)):
        if not expression[i].isdigit():
            newExp += [expression[prev:i], expression[i]]
            prev = i + 1
        if i == len(expression) - 1:
            newExp.append(expression[prev:])

    rst = []
    for op in oper:
        i = 0
        temp = newExp[:]
        while i < 3:
            if op[i] not in temp:
                i += 1
                continue

            ix = temp.index(op[i])
            a = int(temp[ix - 1])
            b = int(temp[ix + 1])

            if op[i] == '+':
                temp[ix - 1] = str(a + b)
            elif op[i] == '-':
                temp[ix - 1] = str(a - b)
            elif op[i] == '*':
                temp[ix - 1] = str(a * b)
            temp.pop(ix)
            temp.pop(ix)

        if int(temp[0]) < 0:
            rst.append(-int(temp[0]))
        else:
            rst.append(int(temp[0]))

    return max(rst)


print(solution("50*6-3*2"))
