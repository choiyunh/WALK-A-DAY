from itertools import combinations
import math


def isPrime(num):
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def solution(nums):
    answer = 0
    comList = list(combinations(nums, 3))
    # print(comList)
    for item in comList:
        if isPrime(sum(item)):
            answer += 1
    return answer


print(solution([1, 2, 7, 6, 4]))