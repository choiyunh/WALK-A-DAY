class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit, minBuy = 0, prices[0]

        for price in prices[1:]:
            minBuy = minBuy if minBuy < price else price
            maxProfit = maxProfit if maxProfit > price - minBuy else price - minBuy

        return maxProfit
