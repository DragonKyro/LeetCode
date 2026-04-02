import java.util.*;

class Solution {
    public int duplicateNumbersXOR(int[] nums) {
        Map<Integer,Integer> cnt = new HashMap<>();
        for (int x : nums) cnt.merge(x, 1, Integer::sum);
        int res = 0;
        for (var e : cnt.entrySet()) if (e.getValue() == 2) res ^= e.getKey();
        return res;
    }
}
