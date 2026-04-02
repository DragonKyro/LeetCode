class Solution:
    def minDominoRotations(self, tops: list[int], bottoms: list[int]) -> int:
        def check(target: int) -> int:
            rot_top = rot_bot = 0
            for i in range(len(tops)):
                if tops[i] != target and bottoms[i] != target:
                    return -1
                elif tops[i] != target:
                    rot_top += 1
                elif bottoms[i] != target:
                    rot_bot += 1
            return min(rot_top, rot_bot)
        res = check(tops[0])
        if res != -1:
            return res
        return check(bottoms[0])
