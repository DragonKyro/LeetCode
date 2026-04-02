import java.util.*;

class Solution {
    public int[] fairCandySwap(int[] aliceSizes, int[] bobSizes) {
        int sa = 0, sb = 0;
        for (int a : aliceSizes) sa += a;
        for (int b : bobSizes) sb += b;
        int diff = (sb - sa) / 2;
        Set<Integer> bobSet = new HashSet<>();
        for (int b : bobSizes) bobSet.add(b);
        for (int a : aliceSizes) if (bobSet.contains(a + diff)) return new int[]{a, a + diff};
        return new int[]{};
    }
}
