import java.util.*;

class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int n : arr) count.merge(n, 1, Integer::sum);
        List<Integer> counts = new ArrayList<>(count.values());
        Collections.sort(counts);
        int removed = 0;
        for (int c : counts) {
            if (k >= c) { k -= c; removed++; }
            else break;
        }
        return counts.size() - removed;
    }
}
