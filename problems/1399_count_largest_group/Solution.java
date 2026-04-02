import java.util.*;

class Solution {
    public int countLargestGroup(int n) {
        Map<Integer, Integer> groups = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int sum = 0; int x = i; while (x > 0) { sum += x % 10; x /= 10; }
            groups.merge(sum, 1, Integer::sum);
        }
        int max = Collections.max(groups.values());
        return (int) groups.values().stream().filter(v -> v == max).count();
    }
}
