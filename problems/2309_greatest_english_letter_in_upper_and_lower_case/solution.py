class Solution:
    def greatestLetter(self, s: str) -> str:
        chars = set(s)
        for c in 'ZYXWVUTSRQPONMLKJIHGFEDCBA':
            if c in chars and c.lower() in chars:
                return c
        return ''
