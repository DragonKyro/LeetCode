import java.util.*;

class Solution {
    public String reorganizeString(String s) {
        int[] counts = new int[26];
        for (char c : s.toCharArray()) counts[c - 'a']++;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (int i = 0; i < 26; i++) if (counts[i] > 0) pq.offer(new int[]{i, counts[i]});
        StringBuilder sb = new StringBuilder();
        int[] prev = null;
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            sb.append((char)(cur[0] + 'a'));
            if (prev != null && prev[1] > 0) pq.offer(prev);
            cur[1]--;
            prev = cur;
        }
        return sb.length() == s.length() ? sb.toString() : "";
    }
}
