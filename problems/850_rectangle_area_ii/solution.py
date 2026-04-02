from typing import List


class Solution:
    def rectangleArea(self, rectangles: List[List[int]]) -> int:
        MOD = 10**9 + 7
        events = []
        for x1, y1, x2, y2 in rectangles:
            events.append((x1, 0, y1, y2))
            events.append((x2, 1, y1, y2))
        events.sort()
        def calc_y(active):
            total = 0
            cur = -1
            for y1, y2 in sorted(active):
                y1 = max(y1, cur)
                if y1 < y2:
                    total += y2 - y1
                cur = max(cur, y2)
            return total
        active = []
        result = 0
        prev_x = events[0][0]
        for x, typ, y1, y2 in events:
            result = (result + calc_y(active) * (x - prev_x)) % MOD
            if typ == 0:
                active.append((y1, y2))
            else:
                active.remove((y1, y2))
            prev_x = x
        return result
