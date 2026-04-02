import java.util.*;

class Solution {
    public List<List<Integer>> findDifference(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
        for (int n : nums1) s1.add(n);
        for (int n : nums2) s2.add(n);
        List<Integer> r1 = new ArrayList<>(), r2 = new ArrayList<>();
        for (int n : s1) if (!s2.contains(n)) r1.add(n);
        for (int n : s2) if (!s1.contains(n)) r2.add(n);
        return List.of(r1, r2);
    }
}
