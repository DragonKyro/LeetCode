import java.util.*;

class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        if (hand.length % groupSize != 0) return false;
        TreeMap<Integer, Integer> counts = new TreeMap<>();
        for (int c : hand) counts.merge(c, 1, Integer::sum);
        while (!counts.isEmpty()) {
            int first = counts.firstKey();
            for (int i = 0; i < groupSize; i++) {
                int card = first + i;
                if (!counts.containsKey(card)) return false;
                if (counts.get(card) == 1) counts.remove(card);
                else counts.merge(card, -1, Integer::sum);
            }
        }
        return true;
    }
}
