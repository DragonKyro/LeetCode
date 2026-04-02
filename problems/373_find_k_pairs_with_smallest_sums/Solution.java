import java.util.*;

class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> res = new ArrayList<>();
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] + a[1] - b[0] - b[1]);
        for (int i = 0; i < Math.min(k, nums1.length); i++)
            pq.offer(new int[]{nums1[i], nums2[0], 0});
        while (!pq.isEmpty() && res.size() < k) {
            int[] cur = pq.poll();
            res.add(Arrays.asList(cur[0], cur[1]));
            int j = cur[2] + 1;
            if (j < nums2.length)
                pq.offer(new int[]{cur[0], nums2[j], j});
        }
        return res;
    }
}
