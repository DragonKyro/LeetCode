import java.util.*;

class Solution {
    public List<Integer> twoOutOfThree(int[] nums1, int[] nums2, int[] nums3) {
        Set<Integer> s1 = new HashSet<>(), s2 = new HashSet<>(), s3 = new HashSet<>();
        for (int n : nums1) s1.add(n);
        for (int n : nums2) s2.add(n);
        for (int n : nums3) s3.add(n);
        Set<Integer> result = new HashSet<>();
        for (int n : s1) if (s2.contains(n) || s3.contains(n)) result.add(n);
        for (int n : s2) if (s3.contains(n)) result.add(n);
        return new ArrayList<>(result);
    }
}
