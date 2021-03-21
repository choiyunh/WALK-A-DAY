from itertools import permutations
import math


def isPrime(num):
    if num < 2:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def solution(numbers):
    answer = 0
    numList = []

    for i in range(1, len(numbers) + 1):
        pList = list(permutations(numbers, i))
        for p in pList:
            pStr = ''.join(p)
            if int(pStr) not in numList:
                numList.append(int(pStr))
    for n in numList:
        if isPrime(n):
            answer += 1

    return answer


solution('011')
