import java.util.*;

class Solution {
    public int minSetSize(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) cnt.merge(x, 1, Integer::sum);
        List<Integer> counts = new ArrayList<>(cnt.values());
        counts.sort(Collections.reverseOrder());
        int total = 0, half = arr.length / 2;
        for (int i = 0; i < counts.size(); i++) {
            total += counts.get(i);
            if (total >= half) return i + 1;
        }
        return counts.size();
    }
}
