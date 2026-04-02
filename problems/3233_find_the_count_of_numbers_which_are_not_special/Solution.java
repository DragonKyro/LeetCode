import java.util.*;

class Solution {
    public int nonSpecialCount(int l, int r) {
        int limit = (int)Math.sqrt(r);
        boolean[] sieve = new boolean[limit+1];
        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= limit; i++)
            if (sieve[i]) for (int j = i*i; j <= limit; j += i) sieve[j] = false;
        int special = 0;
        for (int p = 2; p <= limit; p++)
            if (sieve[p] && (long)p*p >= l && (long)p*p <= r) special++;
        return (r - l + 1) - special;
    }
}
