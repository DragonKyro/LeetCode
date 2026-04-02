class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        if len(prices) < 2:
            return 0
        hold = -prices[0]
        sold = 0
        rest = 0
        for i in range(1, len(prices)):
            prev_sold = sold
            sold = hold + prices[i]
            hold = max(hold, rest - prices[i])
            rest = max(rest, prev_sold)
        return max(sold, rest)
