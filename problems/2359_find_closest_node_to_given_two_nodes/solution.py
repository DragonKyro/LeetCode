from typing import List


class Solution:
    def closestMeetingNode(self, edges: List[int], node1: int, node2: int) -> int:
        def getDist(start: int) -> dict:
            dist = {}
            d = 0
            while start != -1 and start not in dist:
                dist[start] = d
                d += 1
                start = edges[start]
            return dist
        dist1 = getDist(node1)
        dist2 = getDist(node2)
        result = -1
        minDist = float('inf')
        for node in range(len(edges)):
            if node in dist1 and node in dist2:
                d = max(dist1[node], dist2[node])
                if d < minDist:
                    minDist = d
                    result = node
        return result
