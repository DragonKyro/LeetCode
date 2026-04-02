import java.util.*;

class Solution {
    public long minimumCost(int m, int n, int[] horizontalCut, int[] verticalCut) {
        Arrays.sort(horizontalCut); Arrays.sort(verticalCut);
        int h = horizontalCut.length-1, v = verticalCut.length-1;
        long hp = 1, vp = 1, res = 0;
        while (h >= 0 && v >= 0) {
            if (horizontalCut[h] >= verticalCut[v]) { res += horizontalCut[h--] * vp; hp++; }
            else { res += verticalCut[v--] * hp; vp++; }
        }
        while (h >= 0) res += horizontalCut[h--] * vp;
        while (v >= 0) res += verticalCut[v--] * hp;
        return res;
    }
}
