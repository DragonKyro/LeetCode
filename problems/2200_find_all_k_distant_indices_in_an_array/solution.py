class Solution:
    def findKDistantIndices(self, nums: list[int], key: int, k: int) -> list[int]:
        result: list[int] = []
        n = len(nums)
        for i in range(n):
            for j in range(n):
                if nums[j] == key and abs(i - j) <= k:
                    result.append(i)
                    break
        return result
