class Solution:
    def smallerNumbersThanCurrent(self, nums: list[int]) -> list[int]:
        sorted_nums = sorted(nums)
        rank: dict[int, int] = {}
        for i, x in enumerate(sorted_nums):
            if x not in rank:
                rank[x] = i
        return [rank[x] for x in nums]
