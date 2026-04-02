import java.util.*;

class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        if (source == target) return 0;
        Map<Integer, List<Integer>> stopToRoutes = new HashMap<>();
        for (int i = 0; i < routes.length; i++)
            for (int stop : routes[i])
                stopToRoutes.computeIfAbsent(stop, k -> new ArrayList<>()).add(i);
        Set<Integer> visitedStops = new HashSet<>();
        Set<Integer> visitedRoutes = new HashSet<>();
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        visitedStops.add(source);
        int buses = 0;
        while (!queue.isEmpty()) {
            buses++;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int stop = queue.poll();
                for (int route : stopToRoutes.getOrDefault(stop, new ArrayList<>())) {
                    if (visitedRoutes.contains(route)) continue;
                    visitedRoutes.add(route);
                    for (int next : routes[route]) {
                        if (next == target) return buses;
                        if (visitedStops.add(next)) queue.add(next);
                    }
                }
            }
        }
        return -1;
    }
}
