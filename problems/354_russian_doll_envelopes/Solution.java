import java.util.*;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        Arrays.sort(envelopes, (a, b) -> a[0] == b[0] ? b[1] - a[1] : a[0] - b[0]);
        List<Integer> dp = new ArrayList<>();
        for (int[] e : envelopes) {
            int pos = Collections.binarySearch(dp, e[1]);
            if (pos < 0) pos = -(pos + 1);
            if (pos == dp.size()) dp.add(e[1]);
            else dp.set(pos, e[1]);
        }
        return dp.size();
    }
}
