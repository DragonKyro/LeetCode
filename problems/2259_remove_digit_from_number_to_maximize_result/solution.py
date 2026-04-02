class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        result = ''
        for i, c in enumerate(number):
            if c == digit:
                candidate = number[:i] + number[i+1:]
                result = max(result, candidate)
        return result
