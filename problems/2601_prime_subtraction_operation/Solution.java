import java.util.*;

class Solution {
    public boolean primeSubOperation(int[] nums) {
        boolean[] isP = new boolean[1001]; Arrays.fill(isP, true); isP[0]=isP[1]=false;
        for (int i=2;i*i<=1000;i++) if (isP[i]) for (int j=i*i;j<=1000;j+=i) isP[j]=false;
        int prev = 0;
        for (int n : nums) {
            int best = n;
            for (int p = 2; p < n; p++) {
                if (isP[p] && n-p > prev) { best = n-p; break; }
            }
            if (best <= prev) return false;
            prev = best;
        }
        return true;
    }
}
