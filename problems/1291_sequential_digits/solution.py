class Solution:
    def sequentialDigits(self, low: int, high: int) -> list[int]:
        res: list[int] = []
        for length in range(len(str(low)), len(str(high)) + 1):
            for start in range(1, 10 - length + 1):
                num = 0
                for i in range(length):
                    num = num * 10 + start + i
                if low <= num <= high:
                    res.append(num)
        return res
