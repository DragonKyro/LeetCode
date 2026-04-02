class Solution:
    def findEvenNumbers(self, digits: list[int]) -> list[int]:
        from collections import Counter
        freq = Counter(digits)
        result: list[int] = []
        for num in range(100, 1000, 2):
            needed = Counter(str(num))
            needed = Counter(int(d) for d in str(num))
            if all(freq[d] >= needed[d] for d in needed):
                result.append(num)
        return result
