import java.util.*;

class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for (int[] n : nums1) map.merge(n[0], n[1], Integer::sum);
        for (int[] n : nums2) map.merge(n[0], n[1], Integer::sum);
        int[][] res = new int[map.size()][2];
        int i = 0;
        for (var e : map.entrySet()) { res[i][0] = e.getKey(); res[i][1] = e.getValue(); i++; }
        return res;
    }
}
