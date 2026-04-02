class Solution:
    def findLucky(self, arr: list[int]) -> int:
        from collections import Counter
        cnt = Counter(arr)
        res = -1
        for val, freq in cnt.items():
            if val == freq:
                res = max(res, val)
        return res
