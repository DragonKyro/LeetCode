class Solution:
    def smallestDivisor(self, nums: list[int], threshold: int) -> int:
        import math
        lo, hi = 1, max(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            if sum(math.ceil(x / mid) for x in nums) <= threshold:
                hi = mid
            else:
                lo = mid + 1
        return lo
