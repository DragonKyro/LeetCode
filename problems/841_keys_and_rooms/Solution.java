import java.util.*;

class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        Set<Integer> visited = new HashSet<>();
        Deque<Integer> stack = new ArrayDeque<>();
        stack.push(0);
        while (!stack.isEmpty()) {
            int room = stack.pop();
            if (!visited.add(room)) continue;
            for (int key : rooms.get(room)) if (!visited.contains(key)) stack.push(key);
        }
        return visited.size() == rooms.size();
    }
}
