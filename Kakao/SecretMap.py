def solution(n, arr1, arr2):
    answer = []

    for a, b in zip(arr1, arr2):
        bNum1, bNum2 = format(a, 'b'), format(b, 'b')
        rst1, rst2 = '', ''

        for i in range(n - len(bNum1)):
            rst1 += '0'
        for i in range(n - len(bNum2)):
            rst2 += '0'
        rst1 += bNum1
        rst2 += bNum2

        tmp = ''
        for r1, r2 in zip(rst1, rst2):
            if '1' in [r1, r2]:
                tmp += '#'
            else:
                tmp += ' '
        answer.append(tmp)
    return answer


print(solution(6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]))
