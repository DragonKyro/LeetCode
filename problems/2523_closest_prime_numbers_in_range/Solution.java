import java.util.*;

class Solution {
    public int[] closestPrimes(int left, int right) {
        boolean[] sieve = new boolean[right+1];
        Arrays.fill(sieve, true); sieve[0]=sieve[1]=false;
        for (int i=2;i*i<=right;i++) if (sieve[i]) for (int j=i*i;j<=right;j+=i) sieve[j]=false;
        List<Integer> p = new ArrayList<>();
        for (int i=left;i<=right;i++) if (sieve[i]) p.add(i);
        if (p.size()<2) return new int[]{-1,-1};
        int[] best = {p.get(0),p.get(1)};
        for (int i=1;i<p.size()-1;i++) if (p.get(i+1)-p.get(i)<best[1]-best[0]) best = new int[]{p.get(i),p.get(i+1)};
        return best;
    }
}
