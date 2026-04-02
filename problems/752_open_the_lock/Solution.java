import java.util.*;

class Solution {
    public int openLock(String[] deadends, String target) {
        Set<String> dead = new HashSet<>(Arrays.asList(deadends));
        if (dead.contains("0000")) return -1;
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.offer("0000"); visited.add("0000");
        int turns = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int s = 0; s < size; s++) {
                String state = queue.poll();
                if (state.equals(target)) return turns;
                for (int i = 0; i < 4; i++) {
                    for (int d = -1; d <= 1; d += 2) {
                        int nd = (state.charAt(i) - '0' + d + 10) % 10;
                        String next = state.substring(0,i) + nd + state.substring(i+1);
                        if (!visited.contains(next) && !dead.contains(next)) {
                            visited.add(next); queue.offer(next);
                        }
                    }
                }
            }
            turns++;
        }
        return -1;
    }
}
