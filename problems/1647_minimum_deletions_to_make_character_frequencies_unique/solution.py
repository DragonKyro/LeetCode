class Solution:
    def minDeletions(self, s: str) -> int:
        freq = sorted(Counter(s).values(), reverse=True)
        deletions = 0
        max_allowed = len(s)
        for f in freq:
            if f >= max_allowed:
                deletions += f - max(0, max_allowed)
                f = max(0, max_allowed)
            max_allowed = max(0, f - 1)
        return deletions
