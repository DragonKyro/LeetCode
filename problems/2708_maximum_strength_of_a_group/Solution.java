import java.util.*;

class Solution {
    public long maxStrength(int[] nums) {
        if (nums.length == 1) return nums[0];
        List<Integer> neg = new ArrayList<>(), pos = new ArrayList<>();
        for (int n : nums) { if (n < 0) neg.add(n); else if (n > 0) pos.add(n); }
        Collections.sort(neg);
        if (neg.size() % 2 == 1) neg.remove(neg.size()-1);
        if (neg.isEmpty() && pos.isEmpty()) return 0;
        long res = 1;
        for (int n : neg) res *= n;
        for (int n : pos) res *= n;
        return res;
    }
}
