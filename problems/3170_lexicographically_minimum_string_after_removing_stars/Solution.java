import java.util.*;

class Solution {
    public String clearStars(String s) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> a[0]!=b[0] ? a[0]-b[0] : b[1]-a[1]);
        Set<Integer> removed = new HashSet<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '*') {
                removed.add(i);
                int[] top = pq.poll();
                removed.add(top[1]);
            } else {
                pq.offer(new int[]{s.charAt(i)-'a', i});
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++)
            if (!removed.contains(i)) sb.append(s.charAt(i));
        return sb.toString();
    }
}
