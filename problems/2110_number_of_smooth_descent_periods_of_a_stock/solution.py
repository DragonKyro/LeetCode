class Solution:
    def getDescentPeriods(self, prices: list[int]) -> int:
        result = 0
        count = 1
        for i in range(len(prices)):
            if i > 0 and prices[i] == prices[i - 1] - 1:
                count += 1
            else:
                count = 1
            result += count
        return result
