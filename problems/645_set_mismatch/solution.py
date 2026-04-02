class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        n = len(nums)
        count = [0] * (n + 1)
        for num in nums:
            count[num] += 1
        dup = miss = 0
        for i in range(1, n + 1):
            if count[i] == 2:
                dup = i
            if count[i] == 0:
                miss = i
        return [dup, miss]
