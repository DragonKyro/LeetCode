import java.util.*;

class Solution {
    public int numFactoredBinaryTrees(int[] arr) {
        long MOD = 1_000_000_007;
        Arrays.sort(arr);
        Map<Integer, Long> dp = new HashMap<>();
        for (int x : arr) {
            dp.put(x, 1L);
            for (int y : arr) {
                if ((long) y * y > x) break;
                if (x % y == 0 && dp.containsKey(x / y)) {
                    if (y == x / y) dp.put(x, (dp.get(x) + dp.get(y) * dp.get(y)) % MOD);
                    else dp.put(x, (dp.get(x) + 2 * dp.get(y) % MOD * dp.get(x / y)) % MOD);
                }
            }
        }
        long res = 0;
        for (long v : dp.values()) res = (res + v) % MOD;
        return (int) res;
    }
}
