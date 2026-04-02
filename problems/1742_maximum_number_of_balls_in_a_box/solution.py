class Solution:
    def countBalls(self, lowLimit: int, highLimit: int) -> int:
        boxes = {}
        for i in range(lowLimit, highLimit + 1):
            s = sum(int(d) for d in str(i))
            boxes[s] = boxes.get(s, 0) + 1
        return max(boxes.values())
