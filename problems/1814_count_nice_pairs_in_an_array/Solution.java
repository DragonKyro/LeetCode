import java.util.*;

class Solution {
    public int countNicePairs(int[] nums) {
        long MOD = 1000000007;
        Map<Integer, Integer> map = new HashMap<>();
        long result = 0;
        for (int x : nums) {
            int diff = x - rev(x);
            int cnt = map.getOrDefault(diff, 0);
            result = (result + cnt) % MOD;
            map.put(diff, cnt + 1);
        }
        return (int) result;
    }
    private int rev(int x) {
        int r = 0;
        while (x > 0) { r = r * 10 + x % 10; x /= 10; }
        return r;
    }
}
