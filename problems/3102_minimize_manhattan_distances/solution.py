from typing import List


class Solution:
    def minimumDistance(self, points: List[List[int]]) -> int:
        def calc(skip):
            mx_sum = -float('inf')
            mn_sum = float('inf')
            mx_diff = -float('inf')
            mn_diff = float('inf')
            for i, (x, y) in enumerate(points):
                if i == skip:
                    continue
                s, d = x + y, x - y
                mx_sum = max(mx_sum, s)
                mn_sum = min(mn_sum, s)
                mx_diff = max(mx_diff, d)
                mn_diff = min(mn_diff, d)
            return max(mx_sum - mn_sum, mx_diff - mn_diff)
        mx_sum_i = mn_sum_i = mx_diff_i = mn_diff_i = 0
        for i, (x, y) in enumerate(points):
            s, d = x + y, x - y
            if s > points[mx_sum_i][0] + points[mx_sum_i][1]: mx_sum_i = i
            if s < points[mn_sum_i][0] + points[mn_sum_i][1]: mn_sum_i = i
            if d > points[mx_diff_i][0] - points[mx_diff_i][1]: mx_diff_i = i
            if d < points[mn_diff_i][0] - points[mn_diff_i][1]: mn_diff_i = i
        candidates = {mx_sum_i, mn_sum_i, mx_diff_i, mn_diff_i}
        return min(calc(i) for i in candidates)
