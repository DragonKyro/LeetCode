import java.util.*;

class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int x : arr) cnt.merge(x, 1, Integer::sum);
        int res = -1;
        for (var e : cnt.entrySet())
            if (e.getKey().equals(e.getValue())) res = Math.max(res, e.getKey());
        return res;
    }
}
