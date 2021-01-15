import functools

# 값을 바꾸고 싶을 때 (위치를 바꾸고 싶을 때) 1을 리턴하고
# 그냥 그대로 가고 싶으면 -1을 리턴
# a+b < b+a -> 1
# a+b > b+a -> -1
def compare(a, b):
    return (b + a > a + b) - (a + b > b + a)

def solution(numbers):
    answer = ''

    temp = [str(n) for n in numbers]
    temp = sorted(temp, key=functools.cmp_to_key(compare))

    if temp[0] == '0':
        return '0'

    for s in temp:
        answer += s
    return answer


print(solution([3, 30, 34, 5, 9]))
