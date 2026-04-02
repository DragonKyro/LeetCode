class Solution:
    def commonChars(self, words: list[str]) -> list[str]:
        from collections import Counter
        common = Counter(words[0])
        for word in words[1:]:
            common &= Counter(word)
        return list(common.elements())
