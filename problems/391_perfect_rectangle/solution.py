class Solution:
    def isRectangleCover(self, rectangles: list[list[int]]) -> bool:
        area = 0
        corners = set()
        for x1, y1, x2, y2 in rectangles:
            area += (x2 - x1) * (y2 - y1)
            for corner in [(x1,y1),(x1,y2),(x2,y1),(x2,y2)]:
                if corner in corners:
                    corners.remove(corner)
                else:
                    corners.add(corner)
        if len(corners) != 4:
            return False
        corners = sorted(corners)
        x1, y1 = corners[0]
        x2, y2 = corners[3]
        return area == (x2 - x1) * (y2 - y1)
