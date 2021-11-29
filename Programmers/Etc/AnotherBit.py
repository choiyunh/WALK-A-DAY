# 0 0001
# 0 0010
# 0 0011
# 0 0100
# 0 0101
# 0 0110
# 0 0111
# 0 1000
# 0 1001
# 0 1010
# 0 1011
# 0 1100
# 0 1101
# 0 1110
# 0 1111
# 1 0000
# 1 0001
# 1 0010
# 1 0011
# 1 0100
# 1 0101
# 1 0110
# 1 0111


def solution(numbers):
    answer = []

    for n in numbers:
        if n & 1:
            bit = '0' + format(n, 'b')
            for i in range(len(bit) - 1, -1, -1):
                if bit[i] == '0':
                    bit = bit[:i] + '10' + bit[i + 2:]
                    break
            answer.append(int(bit, 2))
        else:
            answer.append(n + 1)

    return answer


print(solution([2, 7]))
