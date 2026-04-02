class Solution:
    def distanceBetweenBusStops(self, distance: list[int], start: int, destination: int) -> int:
        total = sum(distance)
        clockwise = 0
        if start > destination:
            start, destination = destination, start
        for i in range(start, destination):
            clockwise += distance[i]
        return min(clockwise, total - clockwise)
