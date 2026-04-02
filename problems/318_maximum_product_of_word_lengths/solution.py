class Solution:
    def maxProduct(self, words: list[str]) -> int:
        masks = []
        for w in words:
            mask = 0
            for c in w:
                mask |= 1 << (ord(c) - ord('a'))
            masks.append(mask)
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if masks[i] & masks[j] == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        return res
