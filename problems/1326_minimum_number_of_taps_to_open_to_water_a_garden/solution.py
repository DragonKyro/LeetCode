class Solution:
    def minTaps(self, n: int, ranges: list[int]) -> int:
        max_reach = [0] * (n + 1)
        for i, r in enumerate(ranges):
            left = max(0, i - r)
            right = min(n, i + r)
            max_reach[left] = max(max_reach[left], right)
        taps = 0
        cur_end = 0
        far = 0
        for i in range(n):
            far = max(far, max_reach[i])
            if i == cur_end:
                if far <= cur_end:
                    return -1
                taps += 1
                cur_end = far
        return taps
