class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        from collections import defaultdict
        graph = defaultdict(list)
        for src, dst in sorted(tickets, reverse=True):
            graph[src].append(dst)
        route = []
        def dfs(airport):
            while graph[airport]:
                dfs(graph[airport].pop())
            route.append(airport)
        dfs('JFK')
        return route[::-1]
