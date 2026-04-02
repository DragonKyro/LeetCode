class Solution:
    def minStickers(self, stickers: list[str], target: str) -> int:
        from functools import lru_cache
        from collections import Counter
        sticker_counts = [Counter(s) for s in stickers]
        @lru_cache(maxsize=None)
        def dp(remaining):
            if not remaining:
                return 0
            remaining_count = Counter(remaining)
            result = float('inf')
            for sticker in sticker_counts:
                if remaining[0] not in sticker:
                    continue
                new_remaining = []
                for c, cnt in remaining_count.items():
                    new_remaining.append(c * max(0, cnt - sticker.get(c, 0)))
                new_remaining = ''.join(sorted(''.join(new_remaining)))
                if new_remaining != remaining:
                    result = min(result, 1 + dp(new_remaining))
            return result
        ans = dp(target)
        return ans if ans != float('inf') else -1
