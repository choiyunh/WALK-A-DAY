class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxCandie = max(candies)
        
        return [(c + extraCandies) >= maxCandie for c in candies]
