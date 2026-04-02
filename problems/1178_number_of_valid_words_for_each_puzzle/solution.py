class Solution:
    def findNumOfValidWords(self, words: list[str], puzzles: list[str]) -> list[int]:
        from collections import Counter
        word_masks = Counter()
        for word in words:
            mask = 0
            for ch in word:
                mask |= 1 << (ord(ch) - ord('a'))
            if bin(mask).count('1') <= 7:
                word_masks[mask] += 1
        result = []
        for puzzle in puzzles:
            first = 1 << (ord(puzzle[0]) - ord('a'))
            mask = 0
            for ch in puzzle:
                mask |= 1 << (ord(ch) - ord('a'))
            count = 0
            sub = mask
            while sub:
                if sub & first:
                    count += word_masks.get(sub, 0)
                sub = (sub - 1) & mask
            result.append(count)
        return result
