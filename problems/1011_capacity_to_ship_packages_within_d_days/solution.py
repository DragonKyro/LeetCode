class Solution:
    def shipWithinDays(self, weights: list[int], days: int) -> int:
        left, right = max(weights), sum(weights)
        while left < right:
            mid = (left + right) // 2
            d, cur = 1, 0
            for w in weights:
                if cur + w > mid:
                    d += 1
                    cur = 0
                cur += w
            if d <= days:
                right = mid
            else:
                left = mid + 1
        return left
