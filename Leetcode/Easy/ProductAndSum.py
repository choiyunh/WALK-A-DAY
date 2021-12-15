class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product_ = 1
        sum_ = 0
        while n != 0:
            digit = n % 10
            product_ *= digit
            sum_ += digit
            n //= 10

        return product_ - sum_