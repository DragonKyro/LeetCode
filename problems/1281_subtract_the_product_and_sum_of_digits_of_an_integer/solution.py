class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        product, total = 1, 0
        while n:
            d = n % 10
            product *= d
            total += d
            n //= 10
        return product - total
