class Solution:
    def numDifferentIntegers(self, word: str) -> int:
        import re
        nums = re.findall(r'\d+', word)
        return len(set(int(n) for n in nums))
