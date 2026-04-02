import java.util.*;

class Solution {
    public int flipgame(int[] fronts, int[] backs) {
        Set<Integer> same = new HashSet<>();
        for (int i = 0; i < fronts.length; i++)
            if (fronts[i] == backs[i]) same.add(fronts[i]);
        int res = Integer.MAX_VALUE;
        for (int x : fronts) if (!same.contains(x)) res = Math.min(res, x);
        for (int x : backs) if (!same.contains(x)) res = Math.min(res, x);
        return res == Integer.MAX_VALUE ? 0 : res;
    }
}
