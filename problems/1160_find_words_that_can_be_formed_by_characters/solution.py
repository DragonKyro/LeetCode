class Solution:
    def countCharacters(self, words: list[str], chars: str) -> int:
        from collections import Counter
        char_count = Counter(chars)
        result = 0
        for word in words:
            word_count = Counter(word)
            if all(word_count[c] <= char_count[c] for c in word_count):
                result += len(word)
        return result
