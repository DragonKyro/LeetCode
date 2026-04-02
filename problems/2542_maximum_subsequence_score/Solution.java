import java.util.*;

class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a, b) -> nums2[b] - nums2[a]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long s = 0, ans = 0;
        for (int i : idx) {
            pq.offer(nums1[i]); s += nums1[i];
            if (pq.size() > k) s -= pq.poll();
            if (pq.size() == k) ans = Math.max(ans, s * nums2[i]);
        }
        return ans;
    }
}
