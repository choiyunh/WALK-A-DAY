import functools


# a+b < b+a -> 1
# a+b > b+a -> -1
def compare(a, b):
    return (b + a > a + b) - (a + b > b + a)


# def cmp(a, b):
#     return (b > a) - (a > b)


def solution(numbers):
    answer = ''

    # temp = sorted(numbers, key=functools.cmp_to_key(cmp))
    # print(temp)

    temp = [str(n) for n in numbers]
    temp = sorted(temp, key=functools.cmp_to_key(compare))

    if temp[0] == '0':
        return "0"

    for s in temp:
        answer += s
    return answer


print(solution([3, 30, 34, 5, 9]))
