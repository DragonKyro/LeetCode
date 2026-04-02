class Solution:
    def findIntegers(self, n: int) -> int:
        bits = bin(n)[2:]
        length = len(bits)
        fib = [0] * (length + 2)
        fib[0] = 1
        fib[1] = 2
        for i in range(2, length + 1):
            fib[i] = fib[i - 1] + fib[i - 2]
        result = 0
        prev_bit = 0
        for i in range(length):
            if bits[i] == '1':
                result += fib[length - 1 - i]
                if prev_bit == 1:
                    return result
                prev_bit = 1
            else:
                prev_bit = 0
        return result + 1
