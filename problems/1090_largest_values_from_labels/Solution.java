import java.util.*;

class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a, b) -> values[b] - values[a]);
        Map<Integer, Integer> count = new HashMap<>();
        int ans = 0, picked = 0;
        for (int i : idx) {
            if (picked >= numWanted) break;
            int cnt = count.getOrDefault(labels[i], 0);
            if (cnt < useLimit) {
                ans += values[i];
                count.put(labels[i], cnt + 1);
                picked++;
            }
        }
        return ans;
    }
}
