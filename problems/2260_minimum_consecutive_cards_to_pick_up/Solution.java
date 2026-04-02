import java.util.*;

class Solution {
    public int minimumCardPickup(int[] cards) {
        Map<Integer, Integer> lastSeen = new HashMap<>();
        int result = Integer.MAX_VALUE;
        for (int i = 0; i < cards.length; i++) {
            if (lastSeen.containsKey(cards[i])) {
                result = Math.min(result, i - lastSeen.get(cards[i]) + 1);
            }
            lastSeen.put(cards[i], i);
        }
        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
