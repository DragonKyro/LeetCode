class Solution:
    def createTargetArray(self, nums: list[int], index: list[int]) -> list[int]:
        target: list[int] = []
        for n, i in zip(nums, index):
            target.insert(i, n)
        return target
