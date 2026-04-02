import java.util.*;

class Solution {
    public int maxCount(int[] banned, int n, int maxSum) {
        Set<Integer> b = new HashSet<>();
        for (int x : banned) b.add(x);
        int count = 0, total = 0;
        for (int i = 1; i <= n; i++) {
            if (!b.contains(i)) { if (total+i > maxSum) break; total+=i; count++; }
        }
        return count;
    }
}
