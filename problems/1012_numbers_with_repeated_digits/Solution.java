import java.util.*;

class Solution {
    public int numDupDigitsAtMostN(int n) {
        List<Integer> digits = new ArrayList<>();
        int temp = n + 1;
        while (temp > 0) { digits.add(0, temp % 10); temp /= 10; }
        int k = digits.size(), count = 0;
        for (int i = 1; i < k; i++) count += 9 * perm(9, i - 1);
        Set<Integer> seen = new HashSet<>();
        for (int i = 0; i < k; i++) {
            int d = digits.get(i);
            for (int x = (i == 0 ? 1 : 0); x < d; x++)
                if (!seen.contains(x)) count += perm(9 - i, k - i - 1);
            if (seen.contains(d)) break;
            seen.add(d);
        }
        return n - count;
    }
    private int perm(int n, int k) {
        int res = 1;
        for (int i = 0; i < k; i++) res *= (n - i);
        return res;
    }
}
