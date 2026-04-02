import java.util.*;

class Solution {
    public boolean uniqueOccurrences(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) cnt.merge(x, 1, Integer::sum);
        Set<Integer> seen = new HashSet<>(cnt.values());
        return seen.size() == cnt.size();
    }
}
