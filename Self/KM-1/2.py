# 221126

from collections import defaultdict

def solution(id_list, k):
    answer = 0
    coupon = defaultdict(int)
    for customers in id_list:
        for customer in set(customers.split()):
            if coupon[customer] < k:
                coupon[customer] += 1
                answer += 1
    return answer