import java.util.*;

class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 != 0) return new int[0];
        Arrays.sort(changed);
        Map<Integer, Integer> freq = new TreeMap<>();
        for (int num : changed) freq.merge(num, 1, Integer::sum);
        List<Integer> result = new ArrayList<>();
        for (int num : changed) {
            if (freq.getOrDefault(num, 0) == 0) continue;
            if (freq.getOrDefault(num * 2, 0) == 0) return new int[0];
            result.add(num);
            freq.merge(num, -1, Integer::sum);
            freq.merge(num * 2, -1, Integer::sum);
        }
        return result.stream().mapToInt(Integer::intValue).toArray();
    }
}
