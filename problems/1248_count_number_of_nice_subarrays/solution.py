class Solution:
    def numberOfSubarrays(self, nums: list[int], k: int) -> int:
        count = 0
        prefix = 0
        freq = {0: 1}
        for x in nums:
            prefix += x % 2
            count += freq.get(prefix - k, 0)
            freq[prefix] = freq.get(prefix, 0) + 1
        return count
