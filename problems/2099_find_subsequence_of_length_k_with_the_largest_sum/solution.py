class Solution:
    def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
        indexed = sorted(enumerate(nums), key=lambda x: x[1], reverse=True)[:k]
        indexed.sort(key=lambda x: x[0])
        return [val for _, val in indexed]
