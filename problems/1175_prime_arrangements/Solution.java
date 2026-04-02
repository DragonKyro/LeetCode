import java.util.*;

class Solution {
    public int numPrimeArrangements(int n) {
        int MOD = 1_000_000_007;
        int primes = countPrimes(n);
        long result = 1;
        for (int i = 2; i <= primes; i++) result = result * i % MOD;
        for (int i = 2; i <= n - primes; i++) result = result * i % MOD;
        return (int) result;
    }
    private int countPrimes(int n) {
        if (n < 2) return 0;
        boolean[] sieve = new boolean[n + 1];
        Arrays.fill(sieve, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= n; i++)
            if (sieve[i])
                for (int j = i * i; j <= n; j += i) sieve[j] = false;
        int count = 0;
        for (boolean b : sieve) if (b) count++;
        return count;
    }
}
