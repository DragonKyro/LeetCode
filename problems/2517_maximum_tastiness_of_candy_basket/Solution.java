import java.util.*;

class Solution {
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        int lo = 0, hi = price[price.length-1] - price[0];
        while (lo < hi) {
            int mid = (lo+hi+1)/2, cnt = 1, prev = price[0];
            for (int p : price) if (p-prev>=mid) { cnt++; prev=p; }
            if (cnt >= k) lo = mid; else hi = mid-1;
        }
        return lo;
    }
}
