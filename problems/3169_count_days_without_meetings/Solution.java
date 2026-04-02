import java.util.*;

class Solution {
    public int countDays(int days, int[][] meetings) {
        Arrays.sort(meetings, (a,b) -> a[0]-b[0]);
        int busy = 0, end = 0;
        for (int[] m : meetings) {
            int s = Math.max(m[0], end + 1);
            if (s <= m[1]) { busy += m[1] - s + 1; end = Math.max(end, m[1]); }
        }
        return days - busy;
    }
}
