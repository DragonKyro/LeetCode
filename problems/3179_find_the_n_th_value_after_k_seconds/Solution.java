import java.util.*;

class Solution {
    public int valueAfterKSeconds(int n, int k) {
        int MOD = 1_000_000_007;
        long[] a = new long[n];
        Arrays.fill(a, 1);
        for (int t = 0; t < k; t++)
            for (int i = 1; i < n; i++)
                a[i] = (a[i] + a[i-1]) % MOD;
        return (int)a[n-1];
    }
}
