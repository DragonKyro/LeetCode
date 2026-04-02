class Solution:
    def carPooling(self, trips: list[list[int]], capacity: int) -> bool:
        changes = [0] * 1001
        for num, start, end in trips:
            changes[start] += num
            changes[end] -= num
        current = 0
        for c in changes:
            current += c
            if current > capacity:
                return False
        return True
