class Solution:
    def minimumDeletions(self, s: str) -> int:
        b_count = 0
        result = 0
        for c in s:
            if c == 'b':
                b_count += 1
            else:
                result = min(result + 1, b_count)
        return result
