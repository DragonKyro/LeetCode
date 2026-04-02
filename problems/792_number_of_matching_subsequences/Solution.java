import java.util.*;

class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        List<Deque<Character>> waiting = new ArrayList<>();
        for (int i = 0; i < 128; i++) waiting.add(new ArrayDeque<>());
        List<List<Deque<Character>>> buckets = new ArrayList<>();
        for (int i = 0; i < 128; i++) buckets.add(new ArrayList<>());
        for (String word : words) {
            Deque<Character> deque = new ArrayDeque<>();
            for (char c : word.toCharArray()) deque.add(c);
            buckets.get(deque.peek()).add(deque);
        }
        int count = 0;
        for (char c : s.toCharArray()) {
            List<Deque<Character>> old = buckets.get(c);
            buckets.set(c, new ArrayList<>());
            for (Deque<Character> deque : old) {
                deque.poll();
                if (deque.isEmpty()) count++;
                else buckets.get(deque.peek()).add(deque);
            }
        }
        return count;
    }
}
