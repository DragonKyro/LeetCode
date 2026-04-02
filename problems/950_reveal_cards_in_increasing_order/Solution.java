import java.util.*;

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int n = deck.length;
        Arrays.sort(deck);
        Deque<Integer> idx = new ArrayDeque<>();
        for (int i = 0; i < n; i++) idx.offer(i);
        int[] result = new int[n];
        for (int card : deck) {
            result[idx.poll()] = card;
            if (!idx.isEmpty()) idx.offer(idx.poll());
        }
        return result;
    }
}
