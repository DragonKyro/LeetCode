from typing import List


class Solution:
    def countPairs(self, nums: List[int]) -> int:
        def almostEqual(a, b):
            if a == b: return True
            sa = list(str(a).zfill(7))
            sb = list(str(b).zfill(7))
            diff = [i for i in range(7) if sa[i] != sb[i]]
            return len(diff) == 2 and sa[diff[0]] == sb[diff[1]] and sa[diff[1]] == sb[diff[0]]
        res = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if almostEqual(nums[i], nums[j]):
                    res += 1
        return res
