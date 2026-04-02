from typing import List


class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        lo, hi = min(nums), max(nums)
        if lo == hi:
            return 0
        n = len(nums)
        bucket_size = max(1, (hi - lo) // (n - 1))
        bucket_count = (hi - lo) // bucket_size + 1
        buckets_min = [float('inf')] * bucket_count
        buckets_max = [float('-inf')] * bucket_count
        for num in nums:
            idx = (num - lo) // bucket_size
            buckets_min[idx] = min(buckets_min[idx], num)
            buckets_max[idx] = max(buckets_max[idx], num)
        res = 0
        prev_max = buckets_max[0]
        for i in range(1, bucket_count):
            if buckets_min[i] == float('inf'):
                continue
            res = max(res, buckets_min[i] - prev_max)
            prev_max = buckets_max[i]
        return res
