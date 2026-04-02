import java.util.*;

class Solution {
    public boolean canCross(int[] stones) {
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for (int s : stones) map.put(s, new HashSet<>());
        map.get(0).add(0);
        for (int stone : stones) {
            for (int k : map.get(stone)) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0 && map.containsKey(stone + step)) {
                        map.get(stone + step).add(step);
                    }
                }
            }
        }
        return !map.get(stones[stones.length - 1]).isEmpty();
    }
}
