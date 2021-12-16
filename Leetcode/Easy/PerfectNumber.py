class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        sum_ = 0
        for n in range(1, int(num ** 0.5) + 1):
            if num % n == 0:
                sum_ += (n + num // n)

        return (sum_ - num) == num if num != 1 else False

