import java.util.*;

class Solution {
    public int maximumNumberOfStringPairs(String[] words) {
        Set<String> seen = new HashSet<>();
        int count = 0;
        for (String w : words) {
            String rev = new StringBuilder(w).reverse().toString();
            if (seen.contains(rev)) count++;
            seen.add(w);
        }
        return count;
    }
}
