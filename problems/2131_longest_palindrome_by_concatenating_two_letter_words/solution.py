class Solution:
    def longestPalindrome(self, words: list[str]) -> int:
        from collections import Counter
        freq = Counter(words)
        length = 0
        has_center = False
        for word, count in freq.items():
            rev = word[::-1]
            if word == rev:
                length += (count // 2) * 4
                if count % 2 == 1:
                    has_center = True
            elif word < rev and rev in freq:
                length += min(count, freq[rev]) * 4
        if has_center:
            length += 2
        return length
