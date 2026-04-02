import java.util.*;

class Solution {
    public int maxTotalReward(int[] rewardValues) {
        TreeSet<Integer> set = new TreeSet<>();
        for (int v : rewardValues) set.add(v);
        java.math.BigInteger dp = java.math.BigInteger.ONE;
        for (int v : set) {
            java.math.BigInteger mask = java.math.BigInteger.ONE.shiftLeft(v).subtract(java.math.BigInteger.ONE);
            dp = dp.or(dp.and(mask).shiftLeft(v));
        }
        return dp.bitLength() - 1;
    }
}
