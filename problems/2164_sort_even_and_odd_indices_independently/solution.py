class Solution:
    def sortEvenOdd(self, nums: list[int]) -> list[int]:
        even = sorted(nums[::2])
        odd = sorted(nums[1::2], reverse=True)
        result: list[int] = []
        ei = oi = 0
        for i in range(len(nums)):
            if i % 2 == 0:
                result.append(even[ei])
                ei += 1
            else:
                result.append(odd[oi])
                oi += 1
        return result
