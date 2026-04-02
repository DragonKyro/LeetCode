import java.util.*;

class Solution {
    public int videoStitching(int[][] clips, int time) {
        Arrays.sort(clips, (a, b) -> a[0] - b[0]);
        int ans = 0, end = 0, farthest = 0, i = 0;
        while (end < time) {
            while (i < clips.length && clips[i][0] <= end)
                farthest = Math.max(farthest, clips[i++][1]);
            if (farthest == end) return -1;
            end = farthest;
            ans++;
        }
        return ans;
    }
}
