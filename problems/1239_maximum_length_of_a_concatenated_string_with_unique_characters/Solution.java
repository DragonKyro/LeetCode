import java.util.*;

class Solution {
    public int maxLength(List<String> arr) {
        List<Integer> dp = new ArrayList<>();
        dp.add(0);
        int res = 0;
        for (String s : arr) {
            int mask = 0; boolean dup = false;
            for (char c : s.toCharArray()) {
                int bit = 1 << (c - 'a');
                if ((mask & bit) != 0) { dup = true; break; }
                mask |= bit;
            }
            if (dup) continue;
            List<Integer> newDp = new ArrayList<>();
            for (int existing : dp) {
                if ((existing & mask) != 0) continue;
                int combined = existing | mask;
                newDp.add(combined);
                res = Math.max(res, Integer.bitCount(combined));
            }
            dp.addAll(newDp);
        }
        return res;
    }
}
