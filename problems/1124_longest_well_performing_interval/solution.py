class Solution:
    def longestWPI(self, hours: list[int]) -> int:
        score = 0
        result = 0
        first = {}
        for i, h in enumerate(hours):
            score += 1 if h > 8 else -1
            if score > 0:
                result = i + 1
            else:
                if score not in first:
                    first[score] = i
                if score - 1 in first:
                    result = max(result, i - first[score - 1])
        return result
