import java.util.*;

class Solution {
    public String nearestPalindromic(String n) {
        int len = n.length();
        long num = Long.parseLong(n);
        Set<Long> candidates = new HashSet<>();
        candidates.add((long)Math.pow(10, len - 1) - 1);
        candidates.add((long)Math.pow(10, len) + 1);
        long prefix = Long.parseLong(n.substring(0, (len + 1) / 2));
        for (long p = prefix - 1; p <= prefix + 1; p++) {
            String s = String.valueOf(p);
            String cand = s + new StringBuilder(s).reverse().substring(len % 2 == 0 ? 0 : 1);
            candidates.add(Long.parseLong(cand));
        }
        candidates.remove(num);
        long closest = -1;
        for (long c : candidates) {
            if (closest == -1 || Math.abs(c - num) < Math.abs(closest - num) ||
                (Math.abs(c - num) == Math.abs(closest - num) && c < closest))
                closest = c;
        }
        return String.valueOf(closest);
    }
}
