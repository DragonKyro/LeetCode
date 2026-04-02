from typing import List


class Solution:
    def countOfPeaks(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        tree = [0] * (n + 1)
        def update(i, delta):
            i += 1
            while i <= n:
                tree[i] += delta
                i += i & (-i)
        def query(i):
            s = 0
            i += 1
            while i > 0:
                s += tree[i]
                i -= i & (-i)
            return s
        def is_peak(i):
            return 0 < i < n - 1 and nums[i] > nums[i-1] and nums[i] > nums[i+1]
        peaks = [False] * n
        for i in range(1, n - 1):
            if is_peak(i):
                peaks[i] = True
                update(i, 1)
        res = []
        for q in queries:
            if q[0] == 1:
                l, r = q[1], q[2]
                if r - l < 2:
                    res.append(0)
                else:
                    res.append(query(r - 1) - query(l))
            else:
                idx, val = q[1], q[2]
                nums[idx] = val
                for i in range(max(1, idx - 1), min(n - 1, idx + 2)):
                    was = peaks[i]
                    now = is_peak(i)
                    if was and not now:
                        update(i, -1)
                        peaks[i] = False
                    elif not was and now:
                        update(i, 1)
                        peaks[i] = True
        return res
