import java.util.*;

class Solution {
    public int miceAndCheese(int[] r1, int[] r2, int k) {
        int n = r1.length;
        Integer[] idx = new Integer[n];
        for (int i = 0; i < n; i++) idx[i] = i;
        Arrays.sort(idx, (a,b) -> (r1[b]-r2[b]) - (r1[a]-r2[a]));
        int ans = 0;
        for (int i = 0; i < n; i++) ans += i < k ? r1[idx[i]] : r2[idx[i]];
        return ans;
    }
}
