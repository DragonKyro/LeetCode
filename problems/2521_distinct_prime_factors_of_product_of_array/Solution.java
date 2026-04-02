import java.util.*;

class Solution {
    public int distinctPrimeFactors(int[] nums) {
        Set<Integer> primes = new HashSet<>();
        for (int n : nums) {
            for (int d=2; d*d<=n; d++) { if (n%d==0) { primes.add(d); while(n%d==0) n/=d; } }
            if (n > 1) primes.add(n);
        }
        return primes.size();
    }
}
