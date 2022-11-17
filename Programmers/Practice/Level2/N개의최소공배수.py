# 221118 N개의 최소공배수
from math import gcd


def solution(arr):
    answer = arr[0]
    for a in arr[1:]:
        answer = (a * answer) // (gcd(a, answer))
    return answer
