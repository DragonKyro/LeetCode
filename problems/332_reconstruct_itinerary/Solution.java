import java.util.*;

class Solution {
    Map<String, PriorityQueue<String>> graph = new HashMap<>();
    List<String> route = new LinkedList<>();
    public List<String> findItinerary(List<List<String>> tickets) {
        for (List<String> t : tickets)
            graph.computeIfAbsent(t.get(0), k -> new PriorityQueue<>()).add(t.get(1));
        dfs("JFK");
        return route;
    }
    void dfs(String airport) {
        PriorityQueue<String> pq = graph.get(airport);
        while (pq != null && !pq.isEmpty())
            dfs(pq.poll());
        route.add(0, airport);
    }
}
