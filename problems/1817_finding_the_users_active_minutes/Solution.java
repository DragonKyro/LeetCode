import java.util.*;

class Solution {
    public int[] findingUsersActiveMinutes(int[][] logs, int k) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int[] log : logs) {
            map.computeIfAbsent(log[0], x -> new HashSet<>()).add(log[1]);
        }
        int[] answer = new int[k];
        for (var entry : map.entrySet()) {
            int uam = entry.getValue().size();
            if (uam <= k) answer[uam - 1]++;
        }
        return answer;
    }
}
