class Solution:
    def mostFrequent(self, nums: list[int], key: int) -> int:
        from collections import Counter
        freq: dict[int, int] = {}
        for i in range(len(nums) - 1):
            if nums[i] == key:
                freq[nums[i + 1]] = freq.get(nums[i + 1], 0) + 1
        return max(freq, key=freq.get)
