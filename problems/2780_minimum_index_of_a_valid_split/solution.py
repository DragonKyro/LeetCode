from typing import List


class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        from collections import Counter
        cnt = Counter(nums)
        dominant = max(cnt, key=cnt.get)
        total = cnt[dominant]
        left_cnt = 0
        for i in range(len(nums) - 1):
            if nums[i] == dominant:
                left_cnt += 1
            if left_cnt * 2 > i + 1 and (total - left_cnt) * 2 > len(nums) - i - 1:
                return i
        return -1
