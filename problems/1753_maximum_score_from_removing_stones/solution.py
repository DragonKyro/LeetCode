class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        stones = sorted([a, b, c])
        if stones[0] + stones[1] <= stones[2]:
            return stones[0] + stones[1]
        return (a + b + c) // 2
