class Solution:
    def binaryGap(self, n: int) -> int:
        last = -1
        result = 0
        i = 0
        while n:
            if n & 1:
                if last >= 0:
                    result = max(result, i - last)
                last = i
            n >>= 1
            i += 1
        return result
