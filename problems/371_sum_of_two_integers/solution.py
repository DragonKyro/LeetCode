class Solution:
    def getSum(self, a: int, b: int) -> int:
        MASK = 0xFFFFFFFF
        MAX = 0x7FFFFFFF
        while b & MASK:
            carry = (a & b) << 1
            a = a ^ b
            b = carry
        return a & MASK if a > MAX else a & MASK if (a & MASK) <= MAX else ~(a ^ MASK)
