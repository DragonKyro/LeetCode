class Solution:
    def maxSumTwoNoOverlap(self, nums: list[int], firstLen: int, secondLen: int) -> int:
        def solve(L: int, M: int) -> int:
            prefix = [0] * (len(nums) + 1)
            for i in range(len(nums)):
                prefix[i+1] = prefix[i] + nums[i]
            maxL = 0
            ans = 0
            for i in range(L + M, len(nums) + 1):
                maxL = max(maxL, prefix[i - M] - prefix[i - M - L])
                ans = max(ans, maxL + prefix[i] - prefix[i - M])
            return ans
        return max(solve(firstLen, secondLen), solve(secondLen, firstLen))
