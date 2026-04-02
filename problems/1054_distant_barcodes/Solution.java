import java.util.*;

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int b : barcodes) count.merge(b, 1, Integer::sum);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[1] - a[1]);
        for (var e : count.entrySet()) pq.add(new int[]{e.getKey(), e.getValue()});
        int[] result = new int[barcodes.length];
        int idx = 0;
        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            for (int i = 0; i < top[1]; i++) {
                result[idx] = top[0];
                idx += 2;
                if (idx >= barcodes.length) idx = 1;
            }
        }
        return result;
    }
}
