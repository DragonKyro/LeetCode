class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        mapping = {}
        idx = 0
        for c in key:
            if c != ' ' and c not in mapping:
                mapping[c] = chr(ord('a') + idx)
                idx += 1
        return ''.join(mapping.get(c, c) for c in message)
