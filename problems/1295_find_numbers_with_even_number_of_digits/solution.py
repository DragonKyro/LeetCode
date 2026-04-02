class Solution:
    def findNumbers(self, nums: list[int]) -> int:
        return sum(1 for x in nums if len(str(x)) % 2 == 0)
