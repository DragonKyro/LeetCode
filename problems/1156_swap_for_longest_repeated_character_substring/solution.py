class Solution:
    def maxRepOpt1(self, text: str) -> int:
        from collections import Counter
        count = Counter(text)
        groups = []
        i = 0
        while i < len(text):
            j = i
            while j < len(text) and text[j] == text[i]:
                j += 1
            groups.append((text[i], j - i))
            i = j
        result = 0
        for i, (ch, length) in enumerate(groups):
            result = max(result, min(length + 1, count[ch]))
            if i + 2 < len(groups) and groups[i + 2][0] == ch and groups[i + 1][1] == 1:
                result = max(result, min(length + groups[i + 2][1] + 1, count[ch]))
        return result
