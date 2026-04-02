from typing import List


class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0
        stop_to_routes = defaultdict(set)
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_routes[stop].add(i)
        visited_stops = {source}
        visited_routes = set()
        queue = deque([source])
        buses = 0
        while queue:
            buses += 1
            for _ in range(len(queue)):
                stop = queue.popleft()
                for route_idx in stop_to_routes[stop]:
                    if route_idx in visited_routes:
                        continue
                    visited_routes.add(route_idx)
                    for next_stop in routes[route_idx]:
                        if next_stop == target:
                            return buses
                        if next_stop not in visited_stops:
                            visited_stops.add(next_stop)
                            queue.append(next_stop)
        return -1
