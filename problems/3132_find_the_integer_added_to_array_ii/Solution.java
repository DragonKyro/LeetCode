import java.util.*;

class Solution {
    public int minimumAddedInteger(int[] nums1, int[] nums2) {
        Arrays.sort(nums1); Arrays.sort(nums2);
        int n = nums1.length, res = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                List<Integer> rem = new ArrayList<>();
                for (int k = 0; k < n; k++) if (k!=i&&k!=j) rem.add(nums1[k]);
                int x = nums2[0] - rem.get(0);
                boolean ok = true;
                for (int k = 0; k < nums2.length; k++)
                    if (rem.get(k) + x != nums2[k]) { ok = false; break; }
                if (ok) res = Math.min(res, x);
            }
        return res;
    }
}
