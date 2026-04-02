from typing import List


class Solution:
    def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
        ball_color = {}
        color_count = {}
        res = []
        for ball, color in queries:
            if ball in ball_color:
                old = ball_color[ball]
                color_count[old] -= 1
                if color_count[old] == 0:
                    del color_count[old]
            ball_color[ball] = color
            color_count[color] = color_count.get(color, 0) + 1
            res.append(len(color_count))
        return res
