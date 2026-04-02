import java.util.*;

class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        Set<Integer> s1 = new HashSet<>(), s2 = new HashSet<>();
        for (int n : nums1) s1.add(n);
        for (int n : nums2) s2.add(n);
        int min = 100;
        for (int n : s1) if (s2.contains(n)) min = Math.min(min, n);
        if (min < 100) return min;
        int a = Collections.min(s1), b = Collections.min(s2);
        return Math.min(a*10+b, b*10+a);
    }
}
