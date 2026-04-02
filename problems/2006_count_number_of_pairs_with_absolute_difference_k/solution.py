class Solution:
    def countKDifference(self, nums: list[int], k: int) -> int:
        count = 0
        freq: dict[int, int] = {}
        for num in nums:
            if num - k in freq:
                count += freq[num - k]
            if num + k in freq:
                count += freq[num + k]
            freq[num] = freq.get(num, 0) + 1
        return count
