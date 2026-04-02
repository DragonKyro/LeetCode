class Solution:
    def countMaxOrSubsets(self, nums: list[int]) -> int:
        max_or = 0
        for num in nums:
            max_or |= num
        count = 0
        n = len(nums)
        for mask in range(1, 1 << n):
            cur = 0
            for i in range(n):
                if mask & (1 << i):
                    cur |= nums[i]
            if cur == max_or:
                count += 1
        return count
