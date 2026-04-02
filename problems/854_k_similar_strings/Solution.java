import java.util.*;

class Solution {
    public int kSimilarity(String s1, String s2) {
        if (s1.equals(s2)) return 0;
        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(s1); visited.add(s1);
        int swaps = 0;
        while (!queue.isEmpty()) {
            swaps++;
            int size = queue.size();
            for (int q = 0; q < size; q++) {
                String curr = queue.poll();
                int i = 0;
                while (curr.charAt(i) == s2.charAt(i)) i++;
                for (int j = i + 1; j < curr.length(); j++) {
                    if (curr.charAt(j) == s2.charAt(i) && curr.charAt(j) != s2.charAt(j)) {
                        char[] arr = curr.toCharArray();
                        char tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;
                        String nxt = new String(arr);
                        if (nxt.equals(s2)) return swaps;
                        if (visited.add(nxt)) queue.add(nxt);
                    }
                }
            }
        }
        return -1;
    }
}
