class Solution:
    def maxHeightOfTriangle(self, red: int, blue: int) -> int:
        def check(a, b):
            row = 1
            while True:
                if row % 2 == 1:
                    a -= row
                    if a < 0: return row - 1
                else:
                    b -= row
                    if b < 0: return row - 1
                row += 1
        return max(check(red, blue), check(blue, red))
