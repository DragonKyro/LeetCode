class Solution:
    def prefixesDivBy5(self, nums: list[int]) -> list[bool]:
        val = 0
        result = []
        for n in nums:
            val = (val * 2 + n) % 5
            result.append(val == 0)
        return result
