def solution(price, money, count):
    requiredMoney = 0

    for p in range(price, price * count + 1, price):
        requiredMoney += p

    return requiredMoney - money if requiredMoney > money else 0