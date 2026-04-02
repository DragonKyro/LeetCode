from typing import List


class Solution:
    def calculateTax(self, brackets: List[List[int]], income: int) -> float:
        tax = 0.0
        prev = 0
        for upper, percent in brackets:
            taxable = min(income, upper) - prev
            if taxable <= 0:
                break
            tax += taxable * percent / 100
            prev = upper
        return tax
